#version 430
in  vec4 vVertex;
out vec3 texCoords;
smooth out vec3 normal;
uniform mat4 projMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;


void main() {
	texCoords = vVertex.xyz;
	gl_Position =  projMatrix * modelViewMatrix * vVertex; 
}
	