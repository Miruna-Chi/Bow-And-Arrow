#pragma once
#include <string>
#include <include/glm.h>
#include <Core/GPU/Mesh.h>

class Shuriken
{
public:
	Mesh* shuriken;

	Shuriken();
	Shuriken(std::string name, glm::vec3 center, float radius, glm::vec3 color);

	Mesh* CreateShuriken(std::string name, glm::vec3 center, float radius, glm::vec3 color);

};

