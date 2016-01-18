#include <glew.h>
#include <stdio.h>

#include "LoadCubeMapRAW.h"


GLuint loadCubeMapRAW(	const char * positive_x_image,
						const char * negative_x_image,
						const char * positive_y_image,
						const char * negative_y_image,
						const char * positive_z_image,
						const char * negative_z_image,
						int width, int height) {

	GLuint texture = NULL;
    GLubyte * data[6];
    FILE * file;
    
    /// open texture data files
    
    
    /// allocate a buffers to hold the imagse (assume 3 channel RGB data)
	fopen_s( &file, positive_x_image, "rb" ); if ( file == NULL ) return -1;
	data[0] = new GLubyte[width * height * 3];
	fread(data[0], width * height * 3, 1, file);
	fclose( file ); ///  close the file 

	fopen_s( &file, negative_x_image, "rb" ); if ( file == NULL ) return -1;
	data[1] = new GLubyte[width * height * 3];
	fread(data[1], width * height * 3, 1, file);
	fclose( file ); 

	fopen_s( &file, positive_y_image, "rb" ); if ( file == NULL ) return -1;
	data[2] = new GLubyte[width * height * 3];
	fread(data[2], width * height * 3, 1, file);
	fclose( file ); 

	fopen_s( &file, negative_y_image, "rb" ); if ( file == NULL ) return -1;
	data[3] = new GLubyte[width * height * 3];
	fread(data[3], width * height * 3, 1, file);
	fclose( file ); 

	fopen_s( &file, positive_z_image, "rb" ); if ( file == NULL ) return -1;
	data[4] = new GLubyte[width * height * 3];
	fread(data[4], width * height * 3, 1, file);
	fclose( file ); 


	fopen_s( &file, negative_z_image, "rb" ); if ( file == NULL ) return -1;
	data[5] = new GLubyte[width * height * 3];
	fread(data[5], width * height * 3, 1, file);
	fclose( file ); 


	/// Now for the OpenGL stuff
	
	/// This call generates a unique name (uint) for a texture (or even an array of textures)
	glGenTextures(1, &texture);

	/// This informs the machine what type of texture the previous call's name refers to.
	/// In this case I want a 2D texture 
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	
	/// Wrapping and filtering options
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	/// This connects the image date with the named texture. Includes the format of the image data
	/// ours is interleaved, meaning rgb-rgb-rgb instead of rrr-ggg-bbb 
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[0]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[1]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[2]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[3]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[4]);
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data[5]);
    
	/// de-allocate the buffers
	for(int i = 0; i< 6; ++i) delete[] data[i];
	
	return texture;	/// return the index
}