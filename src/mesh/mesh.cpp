#include "Mesh.h"

Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
	:_indexCount(indices.size()) //takes in arguments a liist of vertex data(vertices) -- usaully x, y, and z positions and a list of indices -- tells OpenGL how to connect the vertices
	//into triangles
{	//initializer list that sets private member __indexCount to the number of iindices. This will later be used when drawing

	//Generates one vertex array obect and stores its ID in _vao. VAOs store the state/config of vertex attribute pointers
	glGenVertexArrays(1, &_vao);
	//Generates one veertex buffer object(vbo) to store the vertex data(positions, normals, etc)
	glGenBuffers(1, &_vbo);
	//Generates one Element Buffer Object(EBO)), also called an Index Buffer. It stores index data
	glGenBuffers(1, &_ebo);

	//Binds the VAO so that all following configurations(buffers, attributes) are storeed in it.
	glBindVertexArray(_vao);
	//Binds the VBO to the GL_ARRAY_BUFFER target. From now on, any vertex data will be sent to this buffer
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	//Uploads the actual vertex data to the GPU.
	//                             total size in bytes        pointer to raw vertex array  hint to OpenGL that the data won't change often    
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	//Binds the EBO for index data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);

	//Uploads the index data to the GPU, just like vertex data above
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

	//tell OpenGL how to interpret the vertex data
	//             layout location in shader   3 floats per vertex(x, y, z) data type don/t normalizehow far rb/w consecutive vertices offset in the buffer(start at beginning)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	//enabkes the vertex attrivute at location 0
	glEnableVertexAttribArry(0);
	//unbinds the VAO to prevent accidental modifications
	glBindVertexArray(0);
}


Mesh::~Mesh
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_ebo);
} //when the Mesh object is destroyed, it frees the GPU memory used by VAO< VBO, and EBO

void Mesh::Draw() const
{
	glBindVertexArray(_vao); //biinds the VAO
	//Calls function to render the mesh using the index buffer:
	//GL_TRIANGLE = draw triangles , _indexCount = how many indices to draw
	glDrawElements(GL_TRIANGLES, _indexCount, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}