#pragma once
#include <glad/glad.h>
#include <string>

class Shader {
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();
	void use();

private:
	GLuint program;
};