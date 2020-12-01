#include "Archer.h"
#include <iostream>
#include <Core/Engine.h>
using namespace std;

Archer::Archer() {
	bow = NULL;
	string_upper = NULL;
	string_lower = NULL;
	arrow_line = NULL;
	arrow_tr = NULL;
}

Archer::Archer(std::string name, glm::vec3 center, float radius, glm::vec3 color) {
	//circle = CreateCircle(name + "_circ", center, radius, color);
	bow = CreateBow(name + "_bow", center, radius, color);
	string_upper = CreateStringUpper(name + "_strup", center, radius, color);
	string_lower = CreateStringLower(name + "_strlow", center, radius, color);
	arrow_line = CreateArrowLine(name + "_arrln", center, color);
	arrow_tr = CreateArrowTr(name + "_arrtr", center, color);

	//triangle = CreateTriangle(name + "_tr", center, color);
	//tail = CreateTail(name + "_tail", center, color);
}

Mesh* Archer::CreateBow(std::string name, glm::vec3 center, float radius, glm::vec3 color)
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

	Mesh* bow = new Mesh(name);

	std::vector<unsigned short> indices;

	for (int i = triangleAmount * 3 / 4 + 1; i <= triangleAmount; i++) {
		indices.push_back(i);
	}

	for (int i = 1; i < triangleAmount/4 + 2; i++) {
		indices.push_back(i);
	}

	bow->SetDrawMode(GL_LINE_STRIP);
	bow->InitFromData(vertices, indices);
	return bow;
}

Mesh* Archer::CreateStringUpper(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + radius,  0), color),
	};

	std::vector<unsigned short> indices = { 0, 1 };

	Mesh* upper_string = new Mesh(name);
	upper_string->SetDrawMode(GL_LINE_STRIP);
	upper_string->InitFromData(vertices, indices);
	return upper_string;

}

Mesh* Archer::CreateStringLower(std::string name, glm::vec3 center, float radius, glm::vec3 color)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] - radius,  0), color),
	};

	std::vector<unsigned short> indices = { 0, 1 };

	Mesh* lower_string = new Mesh(name);
	lower_string->SetDrawMode(GL_LINE_STRIP);
	lower_string->InitFromData(vertices, indices);
	return lower_string;

}


Mesh* Archer::CreateArrowLine(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 200, center[1],  0), color),
	};

	std::vector<unsigned short> indices = { 0, 1 };

	Mesh* lower_string = new Mesh(name);
	lower_string->SetDrawMode(GL_LINE_STRIP);
	lower_string->InitFromData(vertices, indices);
	return lower_string;
}

Mesh* Archer::CreateArrowTr(std::string name, glm::vec3 center, glm::vec3 color)
{
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0] + 180, center[1] - 10,  0), color),
		VertexFormat(glm::vec3(center[0] + 180, center[1] + 10,  0), color),
		VertexFormat(glm::vec3(center[0] + 200, center[1],  0), color)
	};

	std::vector<unsigned short> indices = { 0, 1, 2 };

	Mesh* triangle = new Mesh(name);
	triangle->InitFromData(vertices, indices);
	return triangle;

}