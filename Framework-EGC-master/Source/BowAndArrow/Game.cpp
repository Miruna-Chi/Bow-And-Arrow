#include "Game.h"

Game::Game() {}

Game::Game(glm::vec3 center, glm::vec3 gameover_color, glm::vec3 levelup_color,
	glm::vec3 score_color) {

	std::vector<VertexFormat> vertices = {

		VertexFormat(glm::vec3(center[0], center[1],  0), score_color),
		VertexFormat(glm::vec3(center[0], center[1] + 10,  0), score_color),
		VertexFormat(glm::vec3(center[0], center[1] + 20,  0), score_color),
		VertexFormat(glm::vec3(center[0] + 10, center[1],  0), score_color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 10,  0), score_color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 20,  0), score_color),
	};


	gameover = CreateGameOver("gameover", center, gameover_color);
	score = CreateScore("score", center, score_color);
	levelup = CreateLevelUp("levelup", center, levelup_color);

	zero = CreateZero("zero", vertices);
	one = CreateOne("one", vertices);
	two = CreateTwo("two", vertices);
	three = CreateThree("three", vertices);
	four = CreateFour("four", vertices);
	five = CreateFive("five", vertices);
	six = CreateSix("six", vertices);
	seven = CreateSeven("seven", vertices);
	eight = CreateEight("eight", vertices);
	nine = CreateNine("nine", vertices);
}

Mesh* Game::CreateGameOver(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		// Y
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] - 10, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 40,  0), color),

		// O
		VertexFormat(glm::vec3(center[0] + 30, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 20,  0), color),

		// U
		VertexFormat(glm::vec3(center[0] + 50, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 50, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1] + 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1],  0), color),

		// D
		VertexFormat(glm::vec3(center[0] - 20, center[1] - 60,  0), color),
		VertexFormat(glm::vec3(center[0] - 20, center[1] - 20,  0), color),
		VertexFormat(glm::vec3(center[0], center[1] - 40,  0), color),

		// I
		VertexFormat(glm::vec3(center[0] + 10, center[1] - 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] - 20,  0), color),

		// E
		VertexFormat(glm::vec3(center[0] + 20, center[1] - 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] - 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] - 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] - 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] - 40,  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] - 20,  0), color),
		
		// D
		VertexFormat(glm::vec3(center[0] + 50, center[1] - 60,  0), color),
		VertexFormat(glm::vec3(center[0] + 50, center[1] - 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1] - 40,  0), color),

		// !
		VertexFormat(glm::vec3(center[0] + 80, center[1] - 60,  10), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] - 55,  0), color),

		VertexFormat(glm::vec3(center[0] + 80, center[1] - 50,  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] - 20,  0), color),
	};

	std::vector<unsigned short> indices = { 
		// Y
		0, 1,
		1, 2,
		1, 3,
		// O
		4, 5,
		5, 6,
		6, 7,
		7, 4,
		// U
		8, 11,
		8, 9,
		10, 11,
		// D
		12, 13,
		12, 14,
		13, 14,
		// I
		15, 16,
		// E
		17, 19,
		17, 20,
		18, 21,
		19, 22,
		// D
		23, 24,
		24, 25,
		23, 25,
		// !
		26, 27,
		28, 29
	};

	Mesh* gameover = new Mesh(name);
	gameover->SetDrawMode(GL_LINES);
	gameover->InitFromData(vertices, indices);
	return gameover;
}

Mesh* Game::CreateScore(std::string name, glm::vec3 center, glm::vec3 color) {
	std::vector<VertexFormat> vertices = {
		// S
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 10,  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 10,  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1] + 20,  0), color),
		
		// C
		VertexFormat(glm::vec3(center[0] + 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 20,  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1] + 20,  0), color),

		// O
		VertexFormat(glm::vec3(center[0] + 40, center[1],  0), color), // 10
		VertexFormat(glm::vec3(center[0] + 50, center[1],  0), color), // 11
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 20,  0), color), // 12
		VertexFormat(glm::vec3(center[0] + 50, center[1] + 20,  0), color), // 13

		// R 
		VertexFormat(glm::vec3(center[0] + 60, center[1],  0), color), // 14
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 10,  0), color), // 15
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 20,  0), color), // 16
		VertexFormat(glm::vec3(center[0] + 70, center[1],  0), color), // 17
		VertexFormat(glm::vec3(center[0] + 70, center[1] + 10,  0), color), // 18
		VertexFormat(glm::vec3(center[0] + 70, center[1] + 20,  0), color), // 19

		// E
		VertexFormat(glm::vec3(center[0] + 80, center[1],  0), color), // 20
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 10,  0), color), // 21
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 20,  0), color), // 22
		VertexFormat(glm::vec3(center[0] + 90, center[1],  0), color), // 23
		VertexFormat(glm::vec3(center[0] + 90, center[1] + 10,  0), color), // 24
		VertexFormat(glm::vec3(center[0] + 90, center[1] + 20,  0), color), // 25

	};

	std::vector<unsigned short> indices = {
		// S
		0, 1,
		1, 2,
		2, 3,
		3, 4, 
		4, 5,

		// C
		6, 7,
		8, 9,
		6, 8,

		// O
		10, 11,
		11, 13,
		12, 13,
		12, 10,

		// R
		14, 16,
		18, 19,
		15, 18,
		16, 19,
		15, 17,

		// E
		20, 22,
		20, 23,
		21, 24,
		22, 25

	};

	Mesh* score = new Mesh(name);
	score->SetDrawMode(GL_LINES);
	score->InitFromData(vertices, indices);
	return score;
}

Mesh* Game::CreateLevelUp(std::string name, glm::vec3 center, glm::vec3 color) {

	std::vector<VertexFormat> vertices = {
		// L
		VertexFormat(glm::vec3(center[0], center[1],  0), color),
		VertexFormat(glm::vec3(center[0], center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 10, center[1],  0), color),

		// E
		VertexFormat(glm::vec3(center[0] + 20, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 20, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 30, center[1] + 30, 0), color),

		// V
		VertexFormat(glm::vec3(center[0] + 45, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 40, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 50, center[1] + 30,  0), color),

		// E
		VertexFormat(glm::vec3(center[0] + 60, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 60, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 70, center[1] + 30, 0), color),

		// L
		VertexFormat(glm::vec3(center[0] + 80, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 80, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 90, center[1],  0), color),

		// U
		VertexFormat(glm::vec3(center[0] + 110, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 110, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 120, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 120, center[1] + 30,  0), color),

		// P
		VertexFormat(glm::vec3(center[0] + 130, center[1],  0), color),
		VertexFormat(glm::vec3(center[0] + 130, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 130, center[1] + 30,  0), color),
		VertexFormat(glm::vec3(center[0] + 140, center[1] + 15,  0), color),
		VertexFormat(glm::vec3(center[0] + 140, center[1] + 30,  0), color),
	};

	std::vector<unsigned short> indices = {
		// L
		0, 1,
		0, 2,
		// E
		3, 5,
		3, 6,
		4, 7,
		5, 8,
		// V
		9, 10,
		9, 11,
		// E
		12, 14,
		12, 15,
		13, 16,
		14, 17,
		// L
		18, 19,
		18, 20,

		//U
		21, 22,
		23, 24,
		21, 23,
		//P
		25, 27,
		26, 28,
		28, 29,
		27, 29

	};

	Mesh* levelup = new Mesh(name);
	levelup->SetDrawMode(GL_LINES);
	levelup->InitFromData(vertices, indices);
	return levelup;
}

Mesh* Game::CreateZero(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		0, 3, 5, 2, 0, 5
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINE_STRIP);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateOne(std::string name, std::vector<VertexFormat> vertices) {
	
	std::vector<unsigned short> indices = {
		0, 2
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINE_STRIP);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateTwo(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		2, 5,
		5, 4,
		4, 1, 
		1, 0,
		0, 3
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateThree(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		0, 3,
		3, 4,
		4, 1,
		4, 5,
		5, 2,
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateFour(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		2, 1,
		1, 4,
		4, 3,
		4, 5
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateFive(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		5, 2,
		2, 1,
		1, 4,
		4, 3,
		3, 0	
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateSix(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		5, 2,
		2, 1,
		1, 4,
		4, 3,
		3, 0,
		0, 1
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateSeven(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		2, 5,
		5, 3
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateEight(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		0, 3, 
		3, 5,
		5, 2,
		2, 0,
		1, 4
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}

Mesh* Game::CreateNine(std::string name, std::vector<VertexFormat> vertices) {

	std::vector<unsigned short> indices = {
		0, 3,
		3, 5,
		5, 2,
		2, 1,
		1, 4
	};

	Mesh* digit = new Mesh(name);
	digit->SetDrawMode(GL_LINES);
	digit->InitFromData(vertices, indices);
	return digit;
}