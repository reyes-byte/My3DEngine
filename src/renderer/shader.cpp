#include "Shader.h"
#include <fstream> //for reading shader files froom disk
#include <sstream> //for reading file contents into a string
#include <stdexcept>

//Creates a new wshader program by takiing the path to the vertex and fragment shader fles
Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
	//Reads the text contents of each shader file into strings
	std::string vertexSource = ReadFile(vertexPath);
	std::string fragmentSource = ReadFile(fragmentPath);
	//Compile each shader from its source using OpenGL
	_progran = glCreateProgram();
	//creates an empty OpenGL shader program
	glAttachShader(_program, vertexShader);
	glAttachShader(_program, fragmentShader);
	//attaches the compiled shaders to the program
	glLinkProgram(_program);
	//Links the program. This final step combines the shaders into a single usable GPU program
	GLint success;
	glGetProgramiv(_program, GL_LINK_STATUS, &success);

	//Checks if linking succedded
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(_program, 512, nullptr, infoLog);
		//If linking failed, retrieves and prints the error log, then throws an exception with the details
		throw std::runtime_error("Shader link error: " + std::string(infoLog));
	}
	//Deletes the shaders. They;re no longer neede after linking
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::~Shader() //deletes the shader program when the Shader object is destroyed to free GPU memory
{
	glDeleteProgram(_program);
}

void Shader::Use() const
{
	glUseProgram(_program); //actives the shader program. All subsequent OpenGL draw calls will use this shader
}

void Shader::SetMat4(const std::string& name, const float* matrix) const
{//                   the name of the uniform variable in GLSL, matrix - pointer to a 16 float matrix(column major order).
	GLint loc = glGetUniformLocation(_program, name.c_str());
	glUniformMatrix4fv(loc, 1, GL_FALSE, matrix); //
}

std::string Shader::ReadFile(const std::string& path)
{
	//Opens the file at path
	std::ifstream file(path);
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open shader file: " + path);
	}

	std::stringstream buffer;
	buffer << file.rdbuf(); // reads the entire content into a std::string and returns it
	return buffer.str(); // returns the file content as a string
}

//Compile a shader
GLuint Shader::CompileShader(GLenum type, const std::string& source)
{
	//Compile GLSL code into a shader object
	GLuint shader = glCreateShader(type);
	//Creates a new shader of type (GL_VERTEX_SHADER or GL_FRAGMENT_SHADER
	const char* src = source.c_str();
	glShaderSource(shader, 1, &src, nullptr);

	//Provides the GLSL source to OpenGL
	glCompileShader(shader);

	//Compiles the shader
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	//Checks if compilation succeeded
	if (!success) {
		char infoLog[512]; //if not, logs the error and throw the exception
		glGetShaderInfoLog(shader, 512, nullptr, infolog);
		throw std::runtime_error("Shader compile error: " + std::string(infoLog));
	}
	return shader; //returns the compiled shader's ID.
}