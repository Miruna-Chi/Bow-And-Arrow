#include "HP.h"

HP::HP() {}

HP::HP(glm::vec3 center, glm::vec3 letter_color, glm::vec3 life_color) {
	H = CreateH("H", center, letter_color);
	P = CreateP("P", center, letter_color);
	Life = CreateLife("Life", center, life_color);
}

Mesh* HP::CreateH(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 50,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 50,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 80,  0), color)

	};

	std::vector<unsigned short> indices = { 
		0, 1, 10,
		0, 11, 10,
		2, 3, 8,
		2, 8, 9,
		4, 5, 6,
		4, 6, 7
	};

	Mesh* H = new Mesh(name);
	H->InitFromData(vertices, indices);
	return H;

}

Mesh* HP::CreateP(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 50, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 50, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 70,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 70,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 80,  0), color)

	};

	std::vector<unsigned short> indices = { 
		0, 1, 10,
		0, 10, 11,
		2, 3, 8,
		2, 9, 8,
		4, 5, 6,
		4, 6, 7
	};

	Mesh* P = new Mesh(name);
	P->InitFromData(vertices, indices);
	return P;

}

Mesh* HP::CreateLife(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0] + 40, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 90, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 90, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 80,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 20,  0), color)

	};

	std::vector<unsigned short> indices = {
		0, 1, 10,
		0, 10, 11,
		2, 3, 8,
		2, 9, 8,
		4, 5, 6,
		4, 7, 6,
		18, 19, 12,
		18, 13, 12,
		16, 17, 14,
		16, 15, 14
	};

	Mesh* Life = new Mesh(name);
	Life->InitFromData(vertices, indices);
	return Life;

}

