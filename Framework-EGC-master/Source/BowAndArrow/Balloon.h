#pragma once

#include <string>
#include <include/glm.h>
#include <Core/GPU/Mesh.h>

class Balloon
{
public:
	Mesh* circle;
	Mesh* tail;
	Mesh* triangle;
	glm::vec3 color; 


	Balloon();
	Balloon(std::string name, glm::vec3 center, float radius, glm::vec3 color);

	Mesh* CreateCircle(std::string name, glm::vec3 center, float radius, glm::vec3 color);
	Mesh* CreateTriangle(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateTail(std::string name, glm::vec3 center, glm::vec3 color);
};

