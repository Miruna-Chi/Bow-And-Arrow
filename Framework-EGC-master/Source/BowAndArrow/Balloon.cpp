#include "Balloon.h"
#include <iostream>
#include <Core/Engine.h>
using namespace std;

Balloon::Balloon() {
	circle = NULL;
	triangle = NULL;
	tail = NULL;
}

Balloon::Balloon(std::string name, glm::vec3 center, float radius, glm::vec3 color) {
	this->color = color;
	circle = CreateCircle(name + "_circ", center, radius, color);
	triangle = CreateTriangle(name + "_tr", center, color);
	tail = CreateTail(name + "_tail", center, color);
}

Mesh* Balloon::CreateCircle(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{

	std::vector<VertexFormat> vertices;
	int triangleAmount = 40;
	float x = center[0], y = center[1];
	vertices.push_back(VertexFormat(center, color));


	for (int i = 0; i < triangleAmount; i++) {
		vertices.push_back(VertexFormat(glm::vec3(
			x + (radius * cos((double)(i * 2 * M_PI) / triangleAmount)), 
			y + (radius * sin((float)(i * 2 * M_PI) / triangleAmount)), 0),
			color));
	}

	Mesh* circle = new Mesh(name);

	std::vector<unsigned short> indices;

	for (int i = 0; i < triangleAmount; i++) {
		indices.push_back(i);
	}
	indices.push_back(1);

	circle->SetDrawMode(GL_TRIANGLE_FAN);
	circle->InitFromData(vertices, indices);
	return circle;
}

Mesh* Balloon::CreateTriangle(std::string name, glm::vec3 center, glm::vec3 color) 
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1] - 25,  0), color),
		VertexFormat(glm::vec3(center[0] - 5, center[1] - 50,  0), color),
		VertexFormat(glm::vec3(center[0] + 3, center[1] - 45,  0), color)
	};

	std::vector<unsigned short> indices = { 0, 1, 2 };

	Mesh* triangle = new Mesh(name);
	triangle->InitFromData(vertices, indices);
	return triangle;

}

Mesh* Balloon::CreateTail(std::string name, glm::vec3 center, glm::vec3 color)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1] - 45,  0), color),
		VertexFormat(glm::vec3(center[0] - 7, center[1] - 55,  0), color),
		VertexFormat(glm::vec3(center[0] + 7, center[1] - 65,  0), color),
		VertexFormat(glm::vec3(center[0] - 7, center[1] - 75,  0), color),
		VertexFormat(glm::vec3(center[0] + 7, center[1] - 85,  0), color),
	};

	std::vector<unsigned short> indices = { 0, 1, 2, 3, 4};

	Mesh* tail = new Mesh(name);
	tail->SetDrawMode(GL_LINE_STRIP);
	tail->InitFromData(vertices, indices);
	return tail;

}
