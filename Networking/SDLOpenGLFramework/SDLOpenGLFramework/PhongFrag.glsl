/// My fragment shader
#version 440

in  vec3 vertNormal;
in  vec3 lightDir;
out vec4 fragColor;



void main() { 
	const vec4 ks = vec4(0.5, 0.5, 0.0, 0.0);
	const vec4 kd = vec4(0.1, 0.4, 0.9, 0.0);
	const vec4 ka = 0.1 * kd; /// Scalar times a vector - operator overload! Everything is overloaded. 
	vec3 reflection = normalize(reflect(-lightDir,vertNormal));
	float diff = max(dot(vertNormal,lightDir),0.0);
	float spec = max(0.0,dot(vertNormal,reflection));
	if(diff != 0.0){
	spec = pow(spec,16.0);
	}
	fragColor = ka + (diff * kd) +(spec * ks);
} 