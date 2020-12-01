#include "Shuriken.h"
#include <iostream>
#include <Core/Engine.h>
using namespace std;

Shuriken::Shuriken() {}

Shuriken::Shuriken(std::string name, glm::vec3 center, float radius, glm::vec3 color) {
	shuriken = CreateShuriken(name, center, radius, color);
}

Mesh* Shuriken::CreateShuriken(std::string name, glm::vec3 center, float radius, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 10,  0), color),

		VertexFormat(glm::vec3(center[0] + 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] - 10,  0), color),

		VertexFormat(glm::vec3(center[0] - 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] - 10, center[1] + 10,  0), color),

		VertexFormat(glm::vec3(center[0], center[1] - 20,  0), color),
		VertexFormat(glm::vec3(center[0] - 10, center[1] - 10,  0), color),
	};

	std::vector<unsigned short> indices = { 
		0, 1, 2, 
		0, 3, 4,
		0, 5, 6,
		0, 7, 8
		};

	Mesh* shuriken = new Mesh(name);
	shuriken->InitFromData(vertices, indices);
	return shuriken;

}
