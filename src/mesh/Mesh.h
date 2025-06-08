#pragma once
//Uploads vertex and index data to the GPU and configures how to read vertex attrivutes
//can be drawn using Draw()
//Cleans yo GPU memory in the desturctor

#include <glad/glad.h>
#include <vector>

class Mesh {
public:
	Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
	~Mesh();
	void Draw() const;

private:
	GLuint _vao, _vbo, _ebo;
	GLsizei _indexCount;
};

#endif