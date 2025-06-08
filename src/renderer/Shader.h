#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>

//This Shader class lets me loads shader code from files and compiiles and links them into a GPU program
//Lets you activate and send uniforms the program and automatically cleans up when done
class Shader {
public:
	Shader(const std::string& vertexPath, const std::string& fragmentPath);
	~Shader();
	void Use() const;
	void SetMat4(const std::string& name, const float* matrix) const;

private:
	GLuint _program;
	std::string ReadFile(const std::string& path);
	Gluint CompileShader(GLenum type, const std::string& source);
};

#endif