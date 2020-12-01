#pragma once
#include <iostream>
#include <Core/Engine.h>

class Powerbar
{
public:
	Mesh* emptybar;
	Mesh* fullbar;

	Powerbar();
	Powerbar(std::string name, glm::vec3 center, glm::vec3 color);

	Mesh* CreatePowerbar(std::string name, glm::vec3 center, glm::vec3 color, bool fill);

};

