#pragma once
#include <iostream>
#include <Core/Engine.h>

class Game
{
public:
	Mesh* gameover;
	Mesh* levelup;

	Mesh* score;

	Mesh* zero;
	Mesh* one;
	Mesh* two;
	Mesh* three;
	Mesh* four;
	Mesh* five;
	Mesh* six;
	Mesh* seven;
	Mesh* eight;
	Mesh* nine;

	Game();
	Game(glm::vec3 center, glm::vec3 gameover_color, glm::vec3 levelup_color,
		glm::vec3 score_color);

	Mesh* CreateGameOver(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateScore(std::string name, glm::vec3 center, glm::vec3 color);
	Mesh* CreateLevelUp(std::string name, glm::vec3 center, glm::vec3 color);

	Mesh* CreateZero(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateOne(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateTwo(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateThree(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateFour(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateFive(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateSix(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateSeven(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateEight(std::string name, std::vector<VertexFormat> vertices);
	Mesh* CreateNine(std::string name, std::vector<VertexFormat> vertices);

};

