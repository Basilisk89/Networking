#include <glew.h>
#include "shader.h"
#include <fstream>   /// needed for the file io 
#include <stdarg.h> /// Needed for variable arguments lists


Shader::Shader(const char *vsFilename, const char *fsFilename) {
	 readCompileAttach(vsFilename,fsFilename);
	 link();
}
Shader::Shader(const char *vsFilename, const char *fsFilename, const char *vertexAttributeName, const char *normalAttributeName, 
				const char* textureCoordAttributeName, const char* colorAttributeName) {
	/// Bind all the named attributes - skip it if NULL
	readCompileAttach(vsFilename,fsFilename);

	if(vertexAttributeName){ 
		glBindAttribLocation(shader, VERTEX_ATTRIB, vertexAttributeName);
		printf("Binding attribute <%s> loc: %d\n",vertexAttributeName, VERTEX_ATTRIB);
	}
	if(normalAttributeName){
		glBindAttribLocation(shader, NORMAL_ATTRIB, normalAttributeName);
		printf("Binding attribute <%s> loc: %d\n",normalAttributeName, NORMAL_ATTRIB);
	}
	if(textureCoordAttributeName){
		glBindAttribLocation(shader, TEXTURE_COORD_ATTRIB, textureCoordAttributeName);
		printf("Binding attribute <%s> loc: %d\n",textureCoordAttributeName, TEXTURE_COORD_ATTRIB);
	}
	if(colorAttributeName){
		glBindAttribLocation(shader, COLOR_ATTRIB, colorAttributeName);
		printf("Binding attribute <%s> loc: %d\n",colorAttributeName, COLOR_ATTRIB);
	}
	link();
}

Shader::Shader(const char *vsFilename, const char *fsFilename, int numAttributes,...) {
	char* name;
	StdAttrib index;
	readCompileAttach(vsFilename,fsFilename);
	
	va_list args;
	va_start(args, numAttributes);
	for(int i = 0; i < numAttributes; ++i){
		index = (StdAttrib) va_arg(args, int);
		name = va_arg(args, char*);
		printf("Binding attribute <%s> loc: %d\n",name, index);
		glBindAttribLocation(shader, index, name);
	}
	va_end(args);	
	link();
}


unsigned int Shader::getStdUniformLoc(StdUniforms name){
	return stdUniformLocation[name];
}

void Shader::handleStdUniforms(char* projectionMatrixName, char* modelViewMatrixName, char* normalMatrixName, char* light_PosName){
	char *stdUniformNames[sizeof(StdUniforms)] = {projectionMatrixName, modelViewMatrixName, normalMatrixName, light_PosName};

	/// This just gets the number of Active Uniforms. There is some code at the bottom of this page 
	/// that show how list all the active Iniforms
	int count;
	glGetProgramiv(shader, GL_ACTIVE_UNIFORMS, &count);
	printf("\nThere are %d active Uniforms\n",count);

	/// Loop over the std uniform names and put the location of that uniform into the stdUniformLocation array
	/// this way I can use a enum to pick the desired Uniform loc
	for(int i=0; i < sizeof(StdUniforms); ++i){
		if(stdUniformNames[i] == NULL) continue;
		stdUniformLocation[i] = glGetUniformLocation(shader, stdUniformNames[i]);
		if(stdUniformLocation[i] != -1){
			printf("%s loc:%d\n",stdUniformNames[i],stdUniformLocation[i]);
		}else{
			printf("%s loc: unused\n",stdUniformNames[i]);
		}
	}
}


/// private: 
void Shader::readCompileAttach(const char *vsFilename, const char *fsFilename){
    GLint status;
	shader = 0;
	vertShader = 0;
	fragShader = 0;
	try { 		
		const char* vsText = readTextFile(vsFilename);
		const char* fsText = readTextFile(fsFilename);
		if (vsText == NULL || fsText == NULL) return;

		vertShader = glCreateShader(GL_VERTEX_SHADER);
		fragShader = glCreateShader(GL_FRAGMENT_SHADER);
		/// Check for errors
		if (vertShader == 0 || fragShader == 0) {
			std::string errorMsg("Can't create a new shader");
			throw errorMsg;
		}
    
		glShaderSource(vertShader, 1, &vsText, 0);   
		glShaderSource(fragShader, 1, &fsText, 0);
    
		glCompileShader(vertShader);
		/// Check for errors
			glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
			if(status == 0) {
				GLsizei errorLogSize = 0;
				std::string errorLog;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogSize);
				errorLog.resize(errorLogSize);
				glGetShaderInfoLog(shader, errorLogSize, &errorLogSize, &errorLog[0]);
				throw errorLog;
			}

		glCompileShader(fragShader);
		/// Check for errors
			glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
			if(status == 0) {
				GLsizei errorLogSize = 0;
				std::string errorLog;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &errorLogSize);
				errorLog.resize(errorLogSize);
				glGetShaderInfoLog(shader, errorLogSize, &errorLogSize, &errorLog[0]);
				throw errorLog;
			}
    
		shader = glCreateProgram();
		glAttachShader(shader, fragShader);
		glAttachShader(shader, vertShader);
		/// release the memory allocated in readTextFile()
		if(vsText) delete[] vsText;
		if(fsText) delete[] fsText;

	}catch(std::string error){
		printf("ERROR:%s\n",&error[0]);
	}
	 
}

void Shader::link(){
	GLint status;
	try{
			glLinkProgram(shader);
			/// Check for errors
			glGetProgramiv(shader, GL_LINK_STATUS, &status);
			if(status == 0) {
				GLsizei errorLogSize = 0;
				std::string errorLog;
				glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &errorLogSize);
				errorLog.resize(errorLogSize);
				glGetProgramInfoLog(shader, errorLogSize, &errorLogSize, &errorLog[0]);
				throw errorLog;
			}
		
	}catch(std::string error){
		printf("ERROR:%s\n",&error[0]);
	}

}

Shader::~Shader() {
	glDetachShader(shader, fragShader);
	glDetachShader(shader, vertShader);  
	glDeleteShader(fragShader);
	glDeleteShader(vertShader);
	glDeleteProgram(shader);
}

unsigned int Shader::getShader() {
	return shader;
}



/// This is some code to explore the various Uniforms that might exist

//void Shader::handleUniforms(){
//	int count;
//	GLsizei actualLen;
//	GLint size;
//	GLint uniArrayStride;
//	GLenum type;
//	char *name;
//	int maxUniLength;
//	unsigned int loc;
//
//	glGetProgramiv(shader, GL_ACTIVE_UNIFORMS, &count);
//	printf("There are %d active Uniforms\n",count);
//	/// get the length of the longest named uniform
//	glGetProgramiv(shader, GL_ACTIVE_UNIFORM_MAX_LENGTH, &maxUniLength);
//
//	/// Create a little buffer to hold the uniform's name 
//	name = (char *)malloc(sizeof(char) * maxUniLength);
//
//	
//	for (int i = 0; i < count; ++i) {
//		/// Get the name of the ith uniform
//		glGetActiveUniform(shader, i, maxUniLength, &actualLen, &size, &type, name);
//		/// Get the (unsigned int) loc for this uniform
//		loc = glGetUniformLocation(shader, name);
//		
//		// -1 indicates that is not an active uniform, although it may be present in a
//		// uniform block
//		
//		glGetActiveUniformsiv(shader, 1, &loc, GL_UNIFORM_ARRAY_STRIDE, &uniArrayStride);
//		printf("<%s> loc:%d stride:%d\n",name,loc);
//	}
//	free(name);
//}







/// Read from a specified file and return a char array from the heap 
/// The memory must be deleted within this class. It may not be the best way 
/// to do this but it is all private and I did delete it! SSF
char* Shader::readTextFile(const char *filename){
	char* buffer = NULL;
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {								/// Open the file
        file.seekg(0, std::ios::end);					/// goto the end of the file
        int bufferSize = (int) file.tellg();			/// Get the length of the file
		if(bufferSize == 0) {							/// If zero, bad file
			std::string errorMsg("Can't read shader file: ");
			std::string str2(filename);
			errorMsg += str2;
			throw errorMsg;								/// Bail out
		}
		buffer = new char[(int)(bufferSize + 1)];		/// Need to NULL terminate the array
        file.seekg(0, std::ios::beg);
        file.read(buffer, bufferSize);
		buffer[bufferSize] = '\0';						/// Add the NULL
		file.close();
    }else { 
		std::string errorMsg("Can't open shader file: ");
		printf("ERROR:%s:%s\n",filename,&errorMsg[0]);
	}
	return buffer;
}

