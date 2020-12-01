#include "Butterfly.h"

Butterfly::Butterfly() {}

Butterfly::Butterfly(glm::vec3 center) {
	glm::vec3 BLUE = glm::vec3(0.05, 0.35, 0.45);
	glm::vec3 WHITE = glm::vec3(1, 1, 1);

	butterfly = CreateButterfly("butterfly");
	bubble = CreateBubble("bubble", center, true, BLUE);
	bubble_contour = CreateBubble("bubble_contour", center, false, WHITE);
}

Mesh* Butterfly::CreateButterfly(std::string name) {
	std::vector<VertexFormat> vertices
	{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(0.1, 0.1, 0.1)), // 0
		VertexFormat(glm::vec3(0, 4, 0), glm::vec3(0.1, 0.1, 0.1)), // 1
		VertexFormat(glm::vec3(1, 2, 0), glm::vec3(0.33, 0.33, 0.33)), // 2

		VertexFormat(glm::vec3(-1, 2, 0), glm::vec3(0.33, 0.33, 0.33)), // 3

		VertexFormat(glm::vec3(0, -6, 0), glm::vec3(0.1, 0.1, 0.1)), // 4
		VertexFormat(glm::vec3(2, -3, 0), glm::vec3(0.33, 0.33, 0.33)), // 5

		VertexFormat(glm::vec3(-2, -3, 0), glm::vec3(0.33, 0.33, 0.33)), // 6

		VertexFormat(glm::vec3(-1.5f, 1, 0), glm::vec3(0, 0.01, 0.2)), // 7
		VertexFormat(glm::vec3(1.5f, 1, 0), glm::vec3(0, 0.01, 0.2)), // 8

		VertexFormat(glm::vec3(2.5, 3, 0), glm::vec3(0.66, 0.66, 0.66)), // 9
		VertexFormat(glm::vec3(1.5, 1, 0), glm::vec3(0.66, 0.66, 0.66)), // 10
		VertexFormat(glm::vec3(0.7, 2.5, 0), glm::vec3(0.66, 0.66, 0.66)), // 11

		VertexFormat(glm::vec3(-2.5, 3, 0), glm::vec3(0.66, 0.66, 0.66)), // 12
		VertexFormat(glm::vec3(-1.5, 1, 0), glm::vec3(0.66, 0.66, 0.66)), // 13
		VertexFormat(glm::vec3(-0.7, 2.5, 0), glm::vec3(0.66, 0.66, 0.66)), // 14

		VertexFormat(glm::vec3(1.5f, 1, 0), glm::vec3(0.5, 0.25, 0.01)), // 15
		VertexFormat(glm::vec3(2, -3, 0), glm::vec3(0.5, 0.25, 0.01)), // 16

		VertexFormat(glm::vec3(-1.5f, 1, 0), glm::vec3(0.5, 0.25, 0.01)), // 17
		VertexFormat(glm::vec3(-2, -3, 0), glm::vec3(0.5, 0.25, 0.01)), // 18

		VertexFormat(glm::vec3(2.5, 3, 0), glm::vec3(0.2, 0.7, 0.7)), // 19
		VertexFormat(glm::vec3(1.5, 1, 0), glm::vec3(0.2, 0.7, 0.7)), // 20
		VertexFormat(glm::vec3(6, 2, 0), glm::vec3(0.2, 0.7, 0.7)), // 21

		VertexFormat(glm::vec3(-2.5, 3, 0), glm::vec3(0.2, 0.7, 0.7)), // 22
		VertexFormat(glm::vec3(-1.5, 1, 0), glm::vec3(0.2, 0.7, 0.7)), // 23
		VertexFormat(glm::vec3(-6, 2, 0), glm::vec3(0.2, 0.7, 0.7)), // 24

		VertexFormat(glm::vec3(5, 4, 0), glm::vec3(0.1, 0.2, 0.5)), // 25
		VertexFormat(glm::vec3(-5, 4, 0), glm::vec3(0.1, 0.2, 0.5)), // 26

		VertexFormat(glm::vec3(5, 4, 0), glm::vec3(0.1, 0.3, 0.5)), // 27
		VertexFormat(glm::vec3(6, 2, 0), glm::vec3(0.1, 0.3, 0.5)), // 28
		VertexFormat(glm::vec3(9, 4.5, 0), glm::vec3(0.1, 0.3, 0.5)), // 29

		VertexFormat(glm::vec3(-5, 4, 0), glm::vec3(0.1, 0.3, 0.5)), // 30
		VertexFormat(glm::vec3(-6, 2, 0), glm::vec3(0.1, 0.3, 0.5)), // 31
		VertexFormat(glm::vec3(-9, 4.5, 0), glm::vec3(0.1, 0.3, 0.5)), // 32

		VertexFormat(glm::vec3(6, 2, 0), glm::vec3(0.1, 0.4, 0.5)), // 33
		VertexFormat(glm::vec3(9, 4.5, 0), glm::vec3(0.1, 0.4, 0.5)), // 34
		VertexFormat(glm::vec3(7.5, -1.5, 0), glm::vec3(0.1, 0.4, 0.5)), // 35

		VertexFormat(glm::vec3(-6, 2, 0), glm::vec3(0.1, 0.4, 0.5)), // 36
		VertexFormat(glm::vec3(-9, 4.5, 0), glm::vec3(0.1, 0.4, 0.5)), // 37
		VertexFormat(glm::vec3(-7.5, -1.5, 0), glm::vec3(0.1, 0.4, 0.5)), // 38

		VertexFormat(glm::vec3(6, 2, 0), glm::vec3(0, 0.1, 0.3)), // 39
		VertexFormat(glm::vec3(7.5, -1.5, 0), glm::vec3(0, 0.1, 0.3)), // 40
		VertexFormat(glm::vec3(6.7, -2, 0), glm::vec3(0, 0.1, 0.3)), // 41

		VertexFormat(glm::vec3(-6, 2, 0), glm::vec3(0, 0.1, 0.3)), // 42
		VertexFormat(glm::vec3(-7.5, -1.5, 0), glm::vec3(0, 0.1, 0.3)), // 43
		VertexFormat(glm::vec3(-6.7, -2, 0), glm::vec3(0, 0.1, 0.3)), // 44

		VertexFormat(glm::vec3(3.7, -3, 0), glm::vec3(0.1, 0.2, 0.3)), // 45
		VertexFormat(glm::vec3(-3.7, -3, 0), glm::vec3(0.1, 0.2, 0.3)), // 46

		VertexFormat(glm::vec3(1.5f, 1, 0), glm::vec3(0.05, 0.05, 0.2)), // 47
		VertexFormat(glm::vec3(6, 2, 0), glm::vec3(0.05, 0.05, 0.2)), // 48
		VertexFormat(glm::vec3(3.7, -3, 0), glm::vec3(0.05, 0.05, 0.2)), // 49

		VertexFormat(glm::vec3(-1.5f, 1, 0), glm::vec3(0.05, 0.05, 0.2)), // 50
		VertexFormat(glm::vec3(-6, 2, 0), glm::vec3(0.05, 0.05, 0.2)), // 51
		VertexFormat(glm::vec3(-3.7, -3, 0), glm::vec3(0.05, 0.05, 0.2)), // 52

		VertexFormat(glm::vec3(2.9, -6, 0), glm::vec3(0.1, 0.6, 0.6)), // 53
		VertexFormat(glm::vec3(3.7, -3, 0), glm::vec3(0.1, 0.6, 0.6)), // 54
		VertexFormat(glm::vec3(2, -3, 0), glm::vec3(0.1, 0.6, 0.6)), // 55

		VertexFormat(glm::vec3(-2.9, -6, 0), glm::vec3(0.1, 0.6, 0.6)), // 56
		VertexFormat(glm::vec3(-3.7, -3, 0), glm::vec3(0.1, 0.6, 0.6)), // 57
		VertexFormat(glm::vec3(-2, -3, 0), glm::vec3(0.1, 0.6, 0.6)), // 58

		VertexFormat(glm::vec3(2.9, -6, 0), glm::vec3(0.05, 0.4, 0.4)), // 59
		VertexFormat(glm::vec3(3.7, -3, 0), glm::vec3(0.05, 0.4, 0.4)), // 60
		VertexFormat(glm::vec3(6.3, -8, 0), glm::vec3(0.1, 0.6, 0.6)), // 61

		VertexFormat(glm::vec3(-2.9, -6, 0), glm::vec3(0.05, 0.4, 0.4)), // 62
		VertexFormat(glm::vec3(-3.7, -3, 0), glm::vec3(0.05, 0.4, 0.4)), // 63
		VertexFormat(glm::vec3(-6.3, -8, 0), glm::vec3(0.1, 0.6, 0.6)), // 64

		VertexFormat(glm::vec3(2.9, -6, 0), glm::vec3(0.05, 0.3, 0.5)), // 65
		VertexFormat(glm::vec3(3.5, -10, 0), glm::vec3(0.05, 0.3, 0.5)), // 66
		VertexFormat(glm::vec3(6.3, -8, 0), glm::vec3(0.05, 0.3, 0.5)), // 67

		VertexFormat(glm::vec3(-2.9, -6, 0), glm::vec3(0.05, 0.3, 0.5)), // 68
		VertexFormat(glm::vec3(-3.5, -10, 0), glm::vec3(0.05, 0.3, 0.5)), // 69
		VertexFormat(glm::vec3(-6.3, -8, 0), glm::vec3(0.05, 0.3, 0.5)), // 70

		VertexFormat(glm::vec3(6.5, -2, 0), glm::vec3(0, 0.2, 0.3)), // 71
		VertexFormat(glm::vec3(3.7, -3, 0), glm::vec3(0.05, 0.2, 0.3)), // 72
		VertexFormat(glm::vec3(6.3, -8, 0), glm::vec3(0.05, 0.2, 0.3)), // 73

		VertexFormat(glm::vec3(-6.5, -2, 0), glm::vec3(0, 0.2, 0.3)), // 74
		VertexFormat(glm::vec3(-3.7, -3, 0), glm::vec3(0.05, 0.2, 0.3)), // 75
		VertexFormat(glm::vec3(-6.3, -8, 0), glm::vec3(0.05, 0.2, 0.3)), // 76

		VertexFormat(glm::vec3(6.5, -2, 0), glm::vec3(0, 0.2, 0.3)), // 77
		VertexFormat(glm::vec3(8, -4.5, 0), glm::vec3(0.1, 0.4, 0.6)), // 78
		VertexFormat(glm::vec3(6.3, -8, 0), glm::vec3(0.05, 0.2, 0.3)), // 79

		VertexFormat(glm::vec3(-6.5, -2, 0), glm::vec3(0, 0.2, 0.3)), // 80
		VertexFormat(glm::vec3(-8, -4.5, 0), glm::vec3(0.1, 0.4, 0.6)), // 81
		VertexFormat(glm::vec3(-6.3, -8, 0), glm::vec3(0.05, 0.2, 0.3)), // 82

		VertexFormat(glm::vec3(0, 4, 0), glm::vec3(0.4, 0.4, 0.4)), // 83
		VertexFormat(glm::vec3(1, 6, 0), glm::vec3(0.4, 0.4, 0.4)), // 84
		VertexFormat(glm::vec3(1, 7, 0), glm::vec3(0.4, 0.4, 0.4)), // 85

		VertexFormat(glm::vec3(0, 4, 0), glm::vec3(0.4, 0.4, 0.4)), // 86
		VertexFormat(glm::vec3(-1, 6, 0), glm::vec3(0.4, 0.4, 0.4)), // 87
		VertexFormat(glm::vec3(-1, 7, 0), glm::vec3(0.4, 0.4, 0.4)), // 88

		VertexFormat(glm::vec3(2, 8, 0), glm::vec3(0.7, 0.7, 0.7)), // 89
		VertexFormat(glm::vec3(1, 6, 0), glm::vec3(0.7, 0.7, 0.7)), // 90
		VertexFormat(glm::vec3(1, 7, 0), glm::vec3(0.7, 0.7, 0.7)), // 91

		VertexFormat(glm::vec3(-2, 8, 0), glm::vec3(0.7, 0.7, 0.7)), // 92
		VertexFormat(glm::vec3(-1, 6, 0), glm::vec3(0.7, 0.7, 0.7)), // 93
		VertexFormat(glm::vec3(-1, 7, 0), glm::vec3(0.7, 0.7, 0.7)), // 94

	};

	std::vector<unsigned short> indices =
	{
		2, 1, 0,
		3, 0, 1,
		4, 5, 0,
		0, 6, 4,
		8, 2, 0,
		0, 3, 7,
		11, 10, 9,
		12, 13, 14,
		0, 16, 15,
		17, 18, 0,
		19, 20, 21,
		24, 23, 22,
		21, 25, 19,
		22, 26, 24,
		27, 28, 29,
		32, 31, 30,
		35, 34, 33,
		36, 37, 38,
		41, 40, 39,
		42, 43, 44,
		45, 41, 39,
		46, 42, 44,
		49, 48, 47,
		50, 51, 52,
		5, 45, 8,
		46, 6, 7,
		53, 54, 55,
		58, 57, 56,
		61, 60, 59,
		62, 63, 64,
		65, 66, 67,
		70, 69, 68,
		71, 72, 73,
		76, 75, 74,
		79, 78, 77,
		80, 81, 82,
		83, 84, 85,
		88, 87, 86,
		91, 90, 89,
		92, 93, 94
	};

	Mesh* butterfly = new Mesh(name);
	butterfly->InitFromData(vertices, indices);
	return butterfly;
}

Mesh* Butterfly::CreateBubble(std::string name, glm::vec3 center, bool fill, glm::vec3 color) {
	
	float radius = 11;

	std::vector<VertexFormat> vertices;
	int triangleAmount = 40;
	float x = center[0], y = center[1] - 0.5;
	vertices.push_back(VertexFormat(center, color));


	for (int i = 0; i < triangleAmount; i++) {
		vertices.push_back(VertexFormat(glm::vec3(
			x + (radius * cos((double)(i * 2 * M_PI) / triangleAmount)),
			y + (radius * sin((float)(i * 2 * M_PI) / triangleAmount)), 0),
			color));
	}

	Mesh* circle = new Mesh(name);

	std::vector<unsigned short> indices;

	if (!fill) {
		circle->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		indices.push_back(0);
		circle->SetDrawMode(GL_TRIANGLE_FAN);
	}

	for (int i = 1; i <= triangleAmount; i++) {
		indices.push_back(i);
	}
	indices.push_back(1);

	circle->InitFromData(vertices, indices);
	return circle;
}
