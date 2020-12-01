#pragma once
#include <iostream>
#include <Core/Engine.h>

class HP
{
public:
	Mesh* H;
	Mesh* P;
	Mesh* Life;

	HP();
	HP(glm::vec3 center, glm::vec3 letter_color, glm::vec3 life_color);

	Mesh* CreateH(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateP(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateLife(std::string name, glm::vec3 center, glm::vec3 color);

};

