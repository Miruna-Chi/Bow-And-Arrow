#include "Powerbar.h"

Powerbar::Powerbar() {}

Powerbar::Powerbar(std::string name, glm::vec3 center, glm::vec3 color) {
	emptybar = CreatePowerbar(name + "_empty", center, color, false);
	fullbar = CreatePowerbar(name + "_full", center, color, true);
}

Mesh* Powerbar::CreatePowerbar(std::string name, glm::vec3 center, glm::vec3 color, bool fill) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 200, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 200, center[1],  0), color),
		
	};

	std::vector<unsigned short> indices = { 0, 1, 2, 3};

	Mesh* powerbar = new Mesh(name);
	if (!fill) {
		powerbar->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}
	powerbar->InitFromData(vertices, indices);
	return powerbar;

}
