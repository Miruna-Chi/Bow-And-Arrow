#pragma once

#include <Component/SimpleScene.h>
#include <Core/Engine.h>

#include <vector>
#include <iostream>
#include <string>

#include "Transform2D.h"
#include "Balloon.h"
#include "Shuriken.h"
#include "Archer.h"
#include "Powerbar.h"
#include "HP.h"
#include "Game.h"
#include "Butterfly.h"

#define NUM_BALLOONS 15
#define NUM_SHURIKENS 6
#define NUM_ARROWS 10
#define NUM_BUTTERFLIES 8

#define ARR_LEN 200
#define SHUR_RADIUS 40

class BowAndArrow : public SimpleScene
{
public:
	BowAndArrow();
	~BowAndArrow();

	void Init() override;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	bool ArrowCollision(float x_arrow_point, float y_arrow_point, float x_obj_center, 
		float y_object_center, float radius);
	bool ArcherCollision(float x_obj_center, float y_object_center, float obj_radius);


	void AddBalloons();
	void AddArcher();
	void AddShurikens();
	void AddPowerBar();
	void AddHP();
	void AddGame();
	void AddButterfly();

	void RenderBalloons(float deltaTime);
	void RenderButterfly();
	void RenderButterflies(float deltaTime);

	void RenderArcher(float deltaTime);
	void RenderShurikens(float deltaTime);
	void RenderPowerbar(float deltaTime);
	void RenderHP(float deltaTime);
	void RenderGameOver();
	void RenderScore();
	void RenderLevelUp(float deltaTime);

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;

protected:
	glm::mat3 modelMatrix;

	glm::vec3 RED = glm::vec3(0.7, 0.12, 0.12);
	glm::vec3 YELLOW = glm::vec3(0.85, 0.6, 0.2);
	glm::vec3 WHITE = glm::vec3(1, 1, 1);
	glm::vec3 TURQOISE = glm::vec3(0, 0.7, 0.7);
	glm::vec3 GRAY = glm::vec3(0.4, 0.4, 0.4);
	glm::vec3 PINK = glm::vec3(1, 0.7, 0.8);

	int window_h = 720;
	int window_w = 1280;

	float translateX = 0, translateY = 0;
	float scaleX = 0, scaleY = 0;
	float radians = 0;
	float angularStep = 0;
	
	float y_target = -100;
	std::vector<float> y_target_line;
	std::vector<float> x_target_line;
	float targetSpeed = 200;
	float ymax_target = window_h + 200	; //720p window -> balloons off the screen

	// compute coordinates of circle
	float cx = 0, cy = 0;
	float radius = 100;
	glm::vec3 center = glm::vec3(cx, cy, 0);

	// Balloons:
	std::vector<Balloon> balloons;
	std::vector<int> color_chance; // chance of being red/yellow for each balloon
	std::vector<float> y_rand_balloons; // all Y coordinates of rand balloons
	std::vector<int> rand_balloons_color;
	std::vector<int> rand_balloons_speed;
	std::vector<bool> rand_balloons; // all currently showing rand ballons

	// Shurikens:
	float shuriken_spawn_time = 0, shuriken_limit = window_w;
	std::vector<float> x_rand_shuriken; // all X coordinates of rand shurikens
	std::vector<float> angle_rand_shuriken; // all angles
	std::vector<int> rand_shuriken_speed;
	std::vector<bool> rand_shurikens; // all currently showing rand ballons

	// Archer:
	float y_archer = 360;
	float x_archer = 100;
	float curve = 1, angle = 0;
	float ymax_archer = window_h - radius * 2;
	float ymin_archer = 1.7 * radius;
	float archer_speed = 400;
	float archer_angle = 0;
	float max_archer_angle = 70;
	float min_archer_angle = -70;

	// Powerbar:
	float power_fill = 0;
	float x_power = 0, y_power = 0;
	float powerbar_length = 200, powerbar_width = 20;
	float max_power = 1000;

	// Arrows:
	bool loaded_arrow = true;
	float reload_time = 50;
	float reload_counter = 0;

	std::vector<bool> release_arrow;
	std::vector<float> arrow_offset_x;
	std::vector<float> arrow_offset_y;
	std::vector<float> arrow_angle;
	std::vector<float> arrow_power;

	// arrow collisions:
	std::vector<bool> balloon_line;
	std::vector<bool> balloon_col;
	std::vector<bool> rand_balloon_col;
	std::vector<bool> shuriken_col;
	std::vector<bool> shuriken_arch_col;

	// Scale factors (after collision): 
	std::vector<float> balloon_disappear;
	std::vector<float> rand_balloon_disappear;
	std::vector<float> shuriken_disappear;

	// player
	int hp = 3;
	int score = 0;
	float levelup_counter = 0;
	int levelup_time = 80;

	bool play_levelup_sound = true;
	bool play_nextlevel = true;
	bool first_level = true;

	// butterfly
	float bubble_rad = 11;
	
	std::vector<Butterfly> butterflies;
	std::vector<float> y_rand_butterflies; // all Y coordinates of rand butterflies
	std::vector<float> x_rand_butterflies;
	std::vector<bool> butterfly_in_flight;

	std::vector<int> rand_butterflie_color;
	std::vector<int> rand_butterflies_speed;
	std::vector<bool> rand_butterflies; // all currently showing rand butterflies
	std::vector<bool> butterfly_line;
	std::vector<bool> butterfly_col;
	std::vector<bool> rand_butterfly_col;
	std::vector<float> butterfly_disappear;
	std::vector<float> rand_butterfly_disappear;

};
