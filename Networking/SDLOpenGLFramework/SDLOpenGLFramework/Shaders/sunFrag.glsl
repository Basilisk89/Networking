/// My fragment shader
#version 430
in  vec3 texCoords;
out vec4 fragColor;
uniform float time;
uniform sampler3D noiseTexture;
uniform sampler3D sunTexture;

void main() { 
		vec4 noiseVec = texture(noiseTexture, texCoords + time);
		vec4 sunVec = texture(sunTexture , texCoords + time);
		float intensity = abs(noiseVec.x - 0.25) +
	       			              abs(noiseVec.y - 0.25) + 
					              abs(noiseVec.z - 0.00625) + 
					              abs(noiseVec.w - 0.003125);
		        intensity = clamp(intensity * 10.0, 1.0, 1.0) ;
		        fragColor = mix(sunVec , noiseVec , intensity ) * 12;
} 

