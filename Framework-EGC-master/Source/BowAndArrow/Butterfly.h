#pragma once
#include <iostream>
#include <Core/Engine.h>
#include "Balloon.h"

class Butterfly
{
public:
	Mesh* butterfly;
	Mesh* bubble;
	Mesh* bubble_contour;

	Butterfly();
	Butterfly(glm::vec3 center);

	Mesh* CreateButterfly(std::string name);
	Mesh* CreateBubble(std::string name, glm::vec3 center, bool fill, glm::vec3 color);
};

