#pragma once

#include <string>
#include <include/glm.h>
#include <Core/GPU/Mesh.h>

class Archer
{
public:
	Mesh* bow;
	Mesh* string_upper;
	Mesh* string_lower;
	Mesh* arrow_line;
	Mesh* arrow_tr;

	Archer();
	Archer(std::string name, glm::vec3 center, float radius, glm::vec3 color);

	Mesh* CreateBow(std::string name, glm::vec3 center, float radius, glm::vec3 color);
	Mesh* CreateStringUpper(std::string name, glm::vec3 center, float radius, glm::vec3 color);
	Mesh* CreateStringLower(std::string name, glm::vec3 center, float radius, glm::vec3 color);
	Mesh* CreateArrowLine(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateArrowTr(std::string name, glm::vec3 center, glm::vec3 color);

};

