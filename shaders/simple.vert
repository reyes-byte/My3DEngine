#version 330 core
layout(location = 0) in vec3 aPos;

uniform mat4 model; //Transforms sphere
unifrom mat4 viewProj; // Camera transform

void main()
{
	gl_Position = viewProj * model * vec4(aPos, 1.0); // 
}
