#pragma once
/// This class is a manager for loading a shader and dealing with what I call
/// Standard attributes and Uniforms

#include <string>  /// needed for std::string standard library string class 

	
class Shader {
public:
	/// enums for the various matricies this class maintains and
	/// enums for all my standard Uniforms.
	enum StdUniforms { PROJECTION_MATRIX, MODELVIEW_MATRIX, NORMAL_MATRIX, LIGHT_POS};
	/// (Did you now in C++ style, enums should start with a Capital letter and each value should all in caps)
	/// Enums of my Standard Vertex Attributes
	enum StdAttrib {VERTEX_ATTRIB, NORMAL_ATTRIB, TEXTURE_COORD_ATTRIB, COLOR_ATTRIB };
private:
	unsigned int shader;
	unsigned int vertShader;
	unsigned int fragShader;
	/// This array holds the actual location (as an unsigned int) of the various standard uniforms.
	/// The index of this array is held in the StdUniforms enum in the header file
	unsigned int stdUniformLocation[sizeof(StdUniforms)];



public:
	/// Creates a shader from the two file names assumes no attributes
	Shader(const char *vsFilename, const char *fsFilename);

	/// Creates a shader from the two file names.
	/// The number of attributes is specified next.
	/// Each attibute is a pair of arguments: The index (or binding loc) as an int followed the name of the shader's attribute (as a char*)
	Shader(const char *vsFilename, const char *fsFilename, int numAttributes,...);

	/// Creates a shader from the two file names.
	/// A "standard" set of attribute has been enumerated within. 
	/// If a Subset of these atrributes is desired, setting its name to NULL will prevent it from being bound
	Shader::Shader(const char *vsFilename, const char *fsFilename, const char *vertexAttributeName, const char *normalAttributeName, 
				   const char* textureCoordAttributeName=NULL, const char* colorAttributeName=NULL);
	
	
	~Shader();

	/// Returns the shader programs location ans an unsigned int
	unsigned int getShader();

	/// A list of "standard" Uniforms has been enumerated within as enum StdUniforms. 
	/// Returns the loc of specifies uniform or -1 if it is not active
	/// (A uniform specified in the shader but not USED in the shader will not be active)
	unsigned int getStdUniformLoc(Shader::StdUniforms name);

	/// Pass the actual names of the "standard" Uniforms as used in the shader.
	/// This function should be called right after the shader is constructed
	void handleStdUniforms(char* projectionMatrixName, char* modelViewMatrixName, char* normalMatrixName, char* lightPosName);


private:	
	char* readTextFile(const char *fileName);	
	void readCompileAttach(const char *vsFilename, const char *fsFilename);
	void link();
};

