#version 440


in  vec4 vVertex;
in  vec4 vNormal;
in  vec4 vColor;
out vec3 vertNormal;
out vec3 lightDir;
 
uniform mat4 projMatrix;
uniform mat4 modelViewMatrix;
uniform mat3 normalMatrix;
uniform vec4 light_Pos;

void main() {
	vertNormal = normalMatrix * vNormal.xyz;
	vec4 eyePos = modelViewMatrix * vVertex;
	lightDir = normalize(light_Pos.xyz - eyePos.xyz);

	gl_Position =  projMatrix * modelViewMatrix * vVertex;
}