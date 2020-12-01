#pragma once
#include "BowAndArrow.h"

#include "irrklang/irrKlang.h"
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

using namespace irrklang;

ISoundEngine* SoundEngine = createIrrKlangDevice();

using namespace std;

BowAndArrow::BowAndArrow()
{
	color_chance.assign(NUM_BALLOONS, 0);
	y_rand_balloons.assign(NUM_BALLOONS, -100);
	rand_balloons.assign(NUM_BALLOONS, false);
	rand_balloons_color.assign(NUM_BALLOONS, 0);
	rand_balloons_speed.assign(NUM_BALLOONS, 0);

	x_rand_shuriken.assign(NUM_SHURIKENS, 1380); // all X coordinates of rand shurikens
	angle_rand_shuriken.assign(NUM_SHURIKENS, 0); // all angles
	rand_shuriken_speed.assign(NUM_SHURIKENS, 1);
	rand_shurikens.assign(NUM_SHURIKENS, false); // all currently showing rand ballons

	release_arrow.assign(NUM_ARROWS, false);
	arrow_offset_x.assign(NUM_ARROWS, 0);
	arrow_offset_y.assign(NUM_ARROWS, 0);
	arrow_angle.assign(NUM_ARROWS, 0);
	arrow_power.assign(NUM_ARROWS, 0);

	balloon_line.assign(NUM_BALLOONS, true);
	balloon_col.assign(NUM_BALLOONS, false);
	rand_balloon_col.assign(NUM_BALLOONS, false);
	shuriken_col.assign(NUM_SHURIKENS, false);
	shuriken_arch_col.assign(NUM_SHURIKENS, false);

	balloon_disappear.assign(NUM_BALLOONS, 1);
	rand_balloon_disappear.assign(NUM_BALLOONS, 1);
	shuriken_disappear.assign(NUM_SHURIKENS, 1);

	y_target_line.assign(NUM_BALLOONS, -100);
	x_target_line.assign(NUM_BALLOONS, 0);

	y_rand_butterflies.assign(NUM_BUTTERFLIES, -100);
	x_rand_butterflies.assign(NUM_BUTTERFLIES,  0);
	rand_butterflies.assign(NUM_BUTTERFLIES, false);
	rand_butterflies_speed.assign(NUM_BUTTERFLIES, 0);
	butterfly_line.assign(NUM_BUTTERFLIES, true);
	butterfly_col.assign(NUM_BUTTERFLIES, false);
	rand_butterfly_col.assign(NUM_BUTTERFLIES, false);
	butterfly_disappear.assign(NUM_BUTTERFLIES, 1);
	rand_butterfly_disappear.assign(NUM_BUTTERFLIES, 1);
	butterfly_in_flight.assign(NUM_BUTTERFLIES, false);
}

BowAndArrow::~BowAndArrow()
{
	SoundEngine->drop();
}

bool BowAndArrow::ArrowCollision(float x_arrow_point, float y_arrow_point, float x_obj_center,
	float y_obj_center, float radius) {

	float dx = x_arrow_point - x_obj_center;
	float dy = y_arrow_point - y_obj_center;
	float distance = sqrt(dx * dx + dy * dy);

	if (distance < radius)
		return true; // ArrowCollision detected
	
	return false;
}

bool BowAndArrow::ArcherCollision(float x_obj_center, float y_obj_center, float obj_radius) {

	float dx = x_archer - x_obj_center;
	float dy = y_archer - y_obj_center;
	float distance = sqrt(dx * dx + dy * dy);

	if (distance < radius + obj_radius)
		if (dx > 0) // shuriken to the archer's left side
		{
			// shuriken center - archer center Ox dist 
			if (dx < obj_radius)
				return true;
			else return false;
		}
		else return true; // ArcherCollision detected

	return false;
}

void BowAndArrow::AddHP() {
	HP hp(center, WHITE, PINK);
	AddMeshToList(hp.H);
	AddMeshToList(hp.P);
	AddMeshToList(hp.Life);
}

void BowAndArrow::AddGame() {
	Game game(center, RED, WHITE, GRAY);
	AddMeshToList(game.gameover);
	AddMeshToList(game.score);
	AddMeshToList(game.levelup);

	AddMeshToList(game.zero);
	AddMeshToList(game.one);
	AddMeshToList(game.two);
	AddMeshToList(game.three);
	AddMeshToList(game.four);
	AddMeshToList(game.five);
	AddMeshToList(game.six);
	AddMeshToList(game.seven);
	AddMeshToList(game.eight);
	AddMeshToList(game.nine);
}

void BowAndArrow::AddBalloons() {

		Balloon red_balloon("red_balloon", center, radius, RED);
		AddMeshToList(red_balloon.circle);
		AddMeshToList(red_balloon.triangle);
		AddMeshToList(red_balloon.tail);

		Balloon yellow_balloon("yellow_balloon", center, radius, YELLOW);
		AddMeshToList(yellow_balloon.circle);
		AddMeshToList(yellow_balloon.triangle);
		AddMeshToList(yellow_balloon.tail);

		balloons.push_back(red_balloon);
		balloons.push_back(yellow_balloon);
}

void BowAndArrow::AddArcher() {
	
	Archer archer("archer", center, radius, WHITE);
	AddMeshToList(archer.bow);
	AddMeshToList(archer.string_lower);
	AddMeshToList(archer.string_upper);
	AddMeshToList(archer.arrow_line);
	AddMeshToList(archer.arrow_tr);
}

void BowAndArrow::AddShurikens() {
	Shuriken shuri("shuriken", center, radius, GRAY);
	AddMeshToList(shuri.shuriken);
}

void BowAndArrow::AddPowerBar() {
	Powerbar power_bar("powerbar", center, TURQOISE);
	AddMeshToList(power_bar.emptybar);
	AddMeshToList(power_bar.fullbar);

}

void BowAndArrow::AddButterfly() {
	Butterfly butterfly(center);
	AddMeshToList(butterfly.butterfly);
	AddMeshToList(butterfly.bubble);
	AddMeshToList(butterfly.bubble_contour);
}

void BowAndArrow::RenderHP(float deltaTime) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(10, window_h - 50);
	modelMatrix *= Transform2D::Scale(0.5, 0.5);

	RenderMesh2D(meshes["H"], shaders["VertexColor"], modelMatrix);
	modelMatrix *= Transform2D::Translate(80, 0);
	RenderMesh2D(meshes["P"], shaders["VertexColor"], modelMatrix);

	if (hp >= 1) {
		modelMatrix *= Transform2D::Translate(90, 0);
		RenderMesh2D(meshes["Life"], shaders["VertexColor"], modelMatrix);

		if (hp >= 2) {
			modelMatrix *= Transform2D::Translate(90, 0);
			RenderMesh2D(meshes["Life"], shaders["VertexColor"], modelMatrix);

			if (hp >= 3) {
				modelMatrix *= Transform2D::Translate(90, 0);
				RenderMesh2D(meshes["Life"], shaders["VertexColor"], modelMatrix);
			}
		}
	}
}

void BowAndArrow::RenderBalloons(float deltaTimeSeconds) {

	float distance = 500;

	// OY balloon movement

	if (y_target <= ymax_target) {
		y_target += targetSpeed * deltaTimeSeconds;
	}
	else {

		// generate another batch of balloons
		for (int i = 0; i < NUM_BALLOONS; i++) {
			color_chance[i] = rand() % 10;
			balloon_line[i] = true;
		}
		y_target = -100;
	}

	// add random balloons 

	if (int(y_target) % 50 == 0) {
		int rand_ind = rand() % NUM_BALLOONS;
		if (rand_balloons[rand_ind] == false) {
			rand_balloons[rand_ind] = true;
			rand_balloons_color[rand_ind] = rand() % 3;
			rand_balloons_speed[rand_ind] = rand() % 3 + 1;
			y_rand_balloons[rand_ind] = -100;
		}
	}

	for (int i = 0; i < NUM_BALLOONS; i++) {
		if (balloon_col[i])
			if (balloon_disappear[i] > 0) {
				balloon_disappear[i] -= 2 * deltaTimeSeconds;
			}
		if (rand_balloon_col[i])
			if (rand_balloon_disappear[i] > 0) {
				rand_balloon_disappear[i] -= 2 * deltaTimeSeconds;
			}
	}

	// random balloons
	for (int i = 0; i < NUM_BALLOONS; i++) {
		if (rand_balloons[i]) {
			if (y_rand_balloons[i] < ymax_target) {

				float x_balloon_center = distance + 50 * i;
				float y_balloon_center = y_rand_balloons[i];
				float rad = 0.3 * radius;

				if (!rand_balloon_col[i]) {
					for (int j = 0; j < NUM_ARROWS; j++) {
						if (release_arrow[j]) {
							float x_arrow_point = arrow_offset_x[j] + cos(arrow_angle[j]) * ARR_LEN;
							float y_arrow_point = arrow_offset_y[j] + sin(arrow_angle[j]) * ARR_LEN;

							rand_balloon_col[i] = ArrowCollision(x_arrow_point, y_arrow_point,
								x_balloon_center, y_balloon_center, rad);

							if (rand_balloon_col[i]) {
								if (rand_balloons_color[i] == 0) // RED balloon
									score++;
								else score--; // YELLOW balloon
								break;
							}
						}
					}
				}

				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Translate(distance + 50 * i, y_rand_balloons[i]);

				if (rand_balloon_col[i]) {

					if (rand_balloon_disappear[i] > 0) {
						modelMatrix *= Transform2D::Scale(rand_balloon_disappear[i], 1);
						y_rand_balloons[i] -= rand_balloons_speed[i] * targetSpeed * deltaTimeSeconds;
					}
					else {
						modelMatrix *= Transform2D::Scale(0, 1);
						rand_balloon_disappear[i] = 1;
						rand_balloon_col[i] = false;
						rand_balloons[i] = false;
					}
				}
				else
					y_rand_balloons[i] += rand_balloons_speed[i] * targetSpeed * deltaTimeSeconds;

				if (rand_balloons_color[i] == 0) {
					RenderMesh2D(meshes["red_balloon_tr"], shaders["VertexColor"], modelMatrix);
					RenderMesh2D(meshes["red_balloon_tail"], shaders["VertexColor"], modelMatrix);
					modelMatrix *= Transform2D::Scale(0.2, 0.3);
					RenderMesh2D(meshes["red_balloon_circ"], shaders["VertexColor"], modelMatrix);
				}
				else if (rand_balloons_color[i] > 0) {
					RenderMesh2D(meshes["yellow_balloon_tr"], shaders["VertexColor"], modelMatrix);
					RenderMesh2D(meshes["yellow_balloon_tail"], shaders["VertexColor"], modelMatrix);
					modelMatrix *= Transform2D::Scale(0.2, 0.3);
					RenderMesh2D(meshes["yellow_balloon_circ"], shaders["VertexColor"], modelMatrix);
				}

			}
			else {
				rand_balloons[i] = false;
			}
		}
	}

	// balloon_line
	for (int i = 0; i < NUM_BALLOONS; i++) {
		distance += 50;

		if (balloon_line[i]) {

			float x_balloon_center = distance;
			float y_balloon_center = y_target;
			float rad = 0.3 * radius;

			if (!balloon_col[i]) {
				for (int j = 0; j < NUM_ARROWS; j++) {
					if (release_arrow[j]) {
						float x_arrow_point = arrow_offset_x[j] + cos(arrow_angle[j]) * ARR_LEN;
						float y_arrow_point = arrow_offset_y[j] + sin(arrow_angle[j]) * ARR_LEN;

						balloon_col[i] = ArrowCollision(x_arrow_point, y_arrow_point,
							x_balloon_center, y_balloon_center, rad);

						if (balloon_col[i]) {
							if (color_chance[i] <= 7) // RED balloon
									score++;
								else score--; // YELLOW balloon
							y_target_line[i] = y_target;
							break;
						}
					}
				}
			}

			modelMatrix = glm::mat3(1);
			

			if (balloon_col[i]) {
				y_target_line[i] -= targetSpeed * deltaTimeSeconds;
				modelMatrix *= Transform2D::Translate(distance, y_target_line[i]);
				if (balloon_disappear[i] > 0) {
					modelMatrix *= Transform2D::Scale(balloon_disappear[i], 1);
				}
				else {
					modelMatrix *= Transform2D::Scale(0, 1);
					balloon_disappear[i] = 1;
					balloon_col[i] = false;
					balloon_line[i] = false;
				}
			}
			else 
				modelMatrix *= Transform2D::Translate(distance, y_target);

			if (color_chance[i] <= 7) {
				RenderMesh2D(meshes["red_balloon_tr"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["red_balloon_tail"], shaders["VertexColor"], modelMatrix);
				modelMatrix *= Transform2D::Scale(0.2, 0.3);
				RenderMesh2D(meshes["red_balloon_circ"], shaders["VertexColor"], modelMatrix);
			}
			else if (color_chance[i] > 7) {
				RenderMesh2D(meshes["yellow_balloon_tr"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["yellow_balloon_tail"], shaders["VertexColor"], modelMatrix);
				modelMatrix *= Transform2D::Scale(0.2, 0.3);
				RenderMesh2D(meshes["yellow_balloon_circ"], shaders["VertexColor"], modelMatrix);
			}
		}
	}
}

void BowAndArrow::RenderShurikens(float deltaTimeSeconds) {

	float distance = 100;

	if (shuriken_spawn_time <= shuriken_limit) {
		shuriken_spawn_time += targetSpeed * deltaTimeSeconds;
	}
	else {
		shuriken_spawn_time = 0;
	}

	// dissapear (ArrowCollision || ArcherCollision)
	for (int i = 0; i < NUM_SHURIKENS; i++) {
		if (shuriken_col[i] || shuriken_arch_col[i])
			if (shuriken_disappear[i] > 0) {
				shuriken_disappear[i] -= 2 * deltaTimeSeconds;
			}
	}

	if (int(shuriken_spawn_time) % 200 == 0) {
		int rand_ind = rand() % NUM_SHURIKENS;
		if (rand_shurikens[rand_ind] == false) {
			rand_shurikens[rand_ind] = true;
			x_rand_shuriken[rand_ind] = window_w + 100;
			rand_balloons_speed[rand_ind] = rand() % 3 + 1;
		}
	}

	for (int i = 0; i < NUM_SHURIKENS; i++) {
		if (rand_shurikens[i]) {
			if (!shuriken_col[i] && !shuriken_arch_col[i]) {
				if (x_rand_shuriken[i] > -50) { // end of screen

					x_rand_shuriken[i] -= rand_shuriken_speed[i] * targetSpeed * deltaTimeSeconds;
					angle_rand_shuriken[i] += (rand_shuriken_speed[i] + 2) * targetSpeed / 25 * deltaTimeSeconds;

					modelMatrix = glm::mat3(1);
					modelMatrix *= Transform2D::Translate(x_rand_shuriken[i], distance + 110 * i);
					modelMatrix *= Transform2D::Rotate(angle_rand_shuriken[i]);
					modelMatrix *= Transform2D::Scale(2, 2);
					RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);
				}
				else {
					rand_shurikens[i] = false;
					x_rand_shuriken[i] = window_w + 50;
				}

				float x_shuriken_center = x_rand_shuriken[i];
				float y_shuriken_center = distance + 110 * i;
				float rad = SHUR_RADIUS;

				for (int j = 0; j < NUM_ARROWS; j++) {
					if (release_arrow[j]) {
						float x_arrow_point = arrow_offset_x[j] + cos(arrow_angle[j]) * ARR_LEN;
						float y_arrow_point = arrow_offset_y[j] + sin(arrow_angle[j]) * ARR_LEN;

						shuriken_col[i] = ArrowCollision(x_arrow_point, y_arrow_point,
							x_shuriken_center, y_shuriken_center, rad);

						if (shuriken_col[i]) {
							break;
						}
					}
				}

				if (!shuriken_col[i]) {
					shuriken_col[i] = ArcherCollision(x_shuriken_center, y_shuriken_center, rad);
					if (shuriken_col[i]) {
						hp--;
						break;
					}
				}
			}
			else {
				if (shuriken_disappear[i] > 0) {
					angle_rand_shuriken[i] += rand_shuriken_speed[i] * targetSpeed / 10 * deltaTimeSeconds;
					modelMatrix = glm::mat3(1);
					modelMatrix *= Transform2D::Translate(x_rand_shuriken[i], distance + 110 * i);
					modelMatrix *= Transform2D::Rotate(angle_rand_shuriken[i]);
					modelMatrix *= Transform2D::Scale(2, 2);
					modelMatrix *= Transform2D::Scale(shuriken_disappear[i], shuriken_disappear[i]);
					RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);
				}
				else {
					shuriken_disappear[i] = 1;
					shuriken_col[i] = false;
					rand_shurikens[i] = false;
				}	
			}
		}
	}
}

void BowAndArrow::RenderArcher(float deltaTimeSeconds) {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(x_archer, y_archer);
	modelMatrix *= Transform2D::Rotate(archer_angle);

	RenderMesh2D(meshes["archer_bow"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["archer_strup"], shaders["VertexColor"], modelMatrix);
	RenderMesh2D(meshes["archer_strlow"], shaders["VertexColor"], modelMatrix);

	if (!loaded_arrow) {
		if (reload_counter < reload_time) {
			reload_counter += 50 * deltaTimeSeconds;
		}
		else {
			loaded_arrow = true;
			reload_counter = 0;
		}
	}
	else {
		RenderMesh2D(meshes["archer_arrln"], shaders["VertexColor"], modelMatrix);
		RenderMesh2D(meshes["archer_arrtr"], shaders["VertexColor"], modelMatrix);
	}

	for (int i = 0; i < NUM_ARROWS; i++)
		if (release_arrow[i]) {
			if ((arrow_offset_x[i] < window_w + 50) && (arrow_offset_y[i] < window_h + 50)) {
				arrow_offset_x[i] += arrow_power[i] * deltaTimeSeconds * cos(arrow_angle[i]);
				arrow_offset_y[i] += arrow_power[i] * deltaTimeSeconds * sin(arrow_angle[i]);

				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Translate(arrow_offset_x[i], arrow_offset_y[i]);
				modelMatrix *= Transform2D::Rotate(arrow_angle[i]);
				RenderMesh2D(meshes["archer_arrln"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["archer_arrtr"], shaders["VertexColor"], modelMatrix);
			}
			else {
				release_arrow[i] = false;
			}
		}
}

void BowAndArrow::RenderPowerbar(float deltaTime) {

	x_power = x_archer;
	y_power = y_archer - radius * 1.5;

	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(x_power, y_power);
	RenderMesh2D(meshes["powerbar_empty"], shaders["VertexColor"], modelMatrix);
	
	modelMatrix *= Transform2D::Scale(power_fill, 1);
	RenderMesh2D(meshes["powerbar_full"], shaders["VertexColor"], modelMatrix);
}

void BowAndArrow::RenderGameOver() {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(window_w / 2, window_h / 2);
	modelMatrix *= Transform2D::Scale(4, 4);
	modelMatrix *= Transform2D::Translate(- 30, 10);
	RenderMesh2D(meshes["gameover"], shaders["VertexColor"], modelMatrix);
}

void BowAndArrow::RenderScore() {
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(10, window_h - 80);
	RenderMesh2D(meshes["score"], shaders["VertexColor"], modelMatrix);

	int distance = 20;
	modelMatrix *= Transform2D::Translate(100 + distance, 0);

	if (score <= 0) {
		score = 0;
	}

	int aux = score;
	int reverse = 0;

	while (aux > 0) {
		reverse = reverse * 10 + aux % 10;
		aux = aux / 10;
	}

	aux = reverse;

	if (aux == 0) {
		RenderMesh2D(meshes["zero"], shaders["VertexColor"], modelMatrix);
	}
	else {
		while (aux > 0) {
			int digit = aux % 10;
			aux = aux / 10;
			if (digit == 0) {
				RenderMesh2D(meshes["zero"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 1) {
				RenderMesh2D(meshes["one"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 2) {
				RenderMesh2D(meshes["two"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 3) {
				RenderMesh2D(meshes["three"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 4) {
				RenderMesh2D(meshes["four"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 5) {
				RenderMesh2D(meshes["five"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 6) {
				RenderMesh2D(meshes["six"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 7) {
				RenderMesh2D(meshes["seven"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 8) {
				RenderMesh2D(meshes["eight"], shaders["VertexColor"], modelMatrix);
			}
			else if (digit == 9) {
				RenderMesh2D(meshes["nine"], shaders["VertexColor"], modelMatrix);
			}
			modelMatrix *= Transform2D::Translate(distance, 0);
		}
		aux = score;
		while (aux % 10 == 0) {
			aux = aux / 10;
			RenderMesh2D(meshes["zero"], shaders["VertexColor"], modelMatrix);
		}
	}
}

void BowAndArrow::RenderLevelUp(float deltaTimeSeconds) {

	if (levelup_counter < levelup_time) {
		levelup_counter += deltaTimeSeconds * 22;

		if (play_levelup_sound) {
			SoundEngine->stopAllSounds();
			SoundEngine->play2D("Source/BowAndArrow/TheWitcher3QuestsCompletedsound.mp3", false);
			play_levelup_sound = false;
		}	

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(window_w / 2, window_h / 2 + 200);
		modelMatrix *= Transform2D::Scale(4, 4);
		modelMatrix *= Transform2D::Translate(-70, -10);

		RenderMesh2D(meshes["levelup"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat3(1);
		modelMatrix *= Transform2D::Translate(window_w / 2, window_h / 2 - 50);
		modelMatrix *= Transform2D::Scale(20, 20);
		RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);
		
	}
	else {
		if (play_nextlevel) {
			SoundEngine->stopAllSounds();
			SoundEngine->play2D("Source/BowAndArrow/Toss a Coin to your Witcher_01.mp3", false);
			play_nextlevel = false;
		}
	}
}

void BowAndArrow::RenderButterflies(float deltaTimeSeconds) {

	float distance = 450;

	// OY butterfly movement

	if (y_target <= ymax_target) {
		y_target += targetSpeed * deltaTimeSeconds;
	}
	else {

		// generate another batch of butterflies
		for (int i = 0; i < NUM_BUTTERFLIES; i++) {
			butterfly_line[i] = true;
		}
		y_target = -100;
	}

	// add random butterflies 

	if (int(y_target) % 50 == 0) {
		int rand_ind = rand() % NUM_BUTTERFLIES;
		if (rand_butterflies[rand_ind] == false) {
			rand_butterflies[rand_ind] = true;
			butterfly_in_flight[rand_ind] = false;
			rand_butterflies_speed[rand_ind] = rand() % 3 + 1;
			y_rand_butterflies[rand_ind] = -100;
		}
	}

	for (int i = 0; i < NUM_BUTTERFLIES; i++) {
		if (butterfly_col[i])
			if (butterfly_disappear[i] > 0) {
				butterfly_disappear[i] -= 2 * deltaTimeSeconds;
			}
		if (rand_butterfly_col[i])
			if (rand_butterfly_disappear[i] > 0) {
				rand_butterfly_disappear[i] -= 2 * deltaTimeSeconds;
			}
	}

	// random butterflies
	for (int i = 0; i < NUM_BUTTERFLIES; i++) {
		if (rand_butterflies[i]) {
			if (y_rand_butterflies[i] < ymax_target) {

				float x_butterfly_center = distance + 110 * i;
				float y_butterfly_center = y_rand_butterflies[i];
				float rad = bubble_rad * 4;

				if (!rand_butterfly_col[i]) {
					for (int j = 0; j < NUM_ARROWS; j++) {
						if (release_arrow[j]) {
							float x_arrow_point = arrow_offset_x[j] + cos(arrow_angle[j]) * ARR_LEN;
							float y_arrow_point = arrow_offset_y[j] + sin(arrow_angle[j]) * ARR_LEN;

							rand_butterfly_col[i] = ArrowCollision(x_arrow_point, y_arrow_point,
								x_butterfly_center, y_butterfly_center, rad);

							if (rand_butterfly_col[i]) {
								x_rand_butterflies[i] = distance + 110 * i;
								score++;
								break;
							}
						}
					}
				}

				modelMatrix = glm::mat3(1);
				modelMatrix *= Transform2D::Translate(distance + 110 * i, y_rand_butterflies[i]);
				modelMatrix *= Transform2D::Scale(4, 4);
				

				if (rand_butterfly_col[i]) {

					if (rand_butterfly_disappear[i] > 0) {
						RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);
						modelMatrix *= Transform2D::Scale(rand_butterfly_disappear[i], 1);
					}
					else {
						modelMatrix *= Transform2D::Scale(0, 1);
						rand_butterfly_disappear[i] = 1;
						butterfly_in_flight[i] = true;
						rand_butterfly_col[i] = false;
						rand_butterflies[i] = false;
					}
				}
				else {
					RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);
					y_rand_butterflies[i] += rand_butterflies_speed[i] * targetSpeed * deltaTimeSeconds;
				}

				RenderMesh2D(meshes["bubble_contour"], shaders["VertexColor"], modelMatrix);
				RenderMesh2D(meshes["bubble"], shaders["VertexColor"], modelMatrix);

			}
			else {
				rand_butterflies[i] = false;
			}
		}
		if (butterfly_in_flight[i]) {
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(x_rand_butterflies[i], y_rand_butterflies[i]);

			modelMatrix *= Transform2D::Rotate(45.0f);
			modelMatrix *= Transform2D::Scale(2, 2);

			RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);

			if (y_rand_butterflies[i] < window_h + 50) {

				y_rand_butterflies[i] += rand_butterflies_speed[i] * targetSpeed * deltaTimeSeconds;
				x_rand_butterflies[i] -= rand_butterflies_speed[i] * targetSpeed * deltaTimeSeconds;

			}
			else butterfly_in_flight[i] = false;
		}
	}

	// butterfly_line
	for (int i = 0; i < NUM_BUTTERFLIES; i++) {

		if (butterfly_line[i]) {

			float x_butterfly_center = distance;
			float y_butterfly_center = y_target;
			float rad = bubble_rad * 4;

			if (!butterfly_col[i]) {
				for (int j = 0; j < NUM_ARROWS; j++) {
					if (release_arrow[j]) {
						float x_arrow_point = arrow_offset_x[j] + cos(arrow_angle[j]) * ARR_LEN;
						float y_arrow_point = arrow_offset_y[j] + sin(arrow_angle[j]) * ARR_LEN;

						butterfly_col[i] = ArrowCollision(x_arrow_point, y_arrow_point,
							x_butterfly_center, y_butterfly_center, rad);

						if (butterfly_col[i]) {
							x_target_line[i] = distance;
							y_target_line[i] = y_target;
							score++;
							break;
						}
					}
				}
			}

			modelMatrix = glm::mat3(1);
			
			if (butterfly_col[i]) {
				modelMatrix *= Transform2D::Translate(x_target_line[i], y_target_line[i]);
				modelMatrix *= Transform2D::Scale(4, 4);

				if (butterfly_disappear[i] > 0) {
					RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);
					modelMatrix *= Transform2D::Scale(butterfly_disappear[i], 1);
				}
				else {
					modelMatrix *= Transform2D::Scale(0, 1);
					butterfly_disappear[i] = 1;
					butterfly_col[i] = false;
					butterfly_line[i] = false;
				}
			}
			else {
				modelMatrix *= Transform2D::Translate(distance, y_target);
				modelMatrix *= Transform2D::Scale(4, 4);
				RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);
			}

			
			RenderMesh2D(meshes["bubble_contour"], shaders["VertexColor"], modelMatrix);
			RenderMesh2D(meshes["bubble"], shaders["VertexColor"], modelMatrix);
		}
		else {
			modelMatrix = glm::mat3(1);
			modelMatrix *= Transform2D::Translate(x_target_line[i], y_target_line[i]);

			modelMatrix *= Transform2D::Rotate(45.0f);
			modelMatrix *= Transform2D::Scale(2, 2);

			RenderMesh2D(meshes["butterfly"], shaders["VertexColor"], modelMatrix);

			if (y_target_line[i] < window_h + 50) {

				y_target_line[i] += (rand_butterflies_speed[i] + 1) * targetSpeed * deltaTimeSeconds;
				x_target_line[i] -= (rand_butterflies_speed[i] + 1) * targetSpeed * deltaTimeSeconds;

			}
		}
		distance += 110;
	}
}

void BowAndArrow::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	ISound* music = SoundEngine->play2D("Source/BowAndArrow/The Witcher 3 - Hunt or Be Hunted  8-bit.mp3", false);


	// initialize tx and ty (the translation steps)
	translateX = 0;
	translateY = 0;

	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;

	// initialize angularStep
	angularStep = 0;

	AddHP();
	AddBalloons();
	AddArcher();
	AddShurikens();
	AddPowerBar();
	AddGame();
	AddButterfly();
	Balloon balloon("Alb", glm::vec3(1, 1, 0), 50, YELLOW);

}

void BowAndArrow::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void BowAndArrow::Update(float deltaTimeSeconds)
{
	if (hp > 0) {
		if (score > 30) {
			first_level = false;
		}
		if (first_level) {
			RenderBalloons(deltaTimeSeconds);
			RenderArcher(deltaTimeSeconds);
			RenderPowerbar(deltaTimeSeconds);
			RenderShurikens(deltaTimeSeconds);
			RenderHP(deltaTimeSeconds);
			RenderScore();
		}
		else if (play_nextlevel){
			float reload_counter = 0;
			release_arrow.assign(NUM_ARROWS, false);
			arrow_offset_x.assign(NUM_ARROWS, 0);
			arrow_offset_y.assign(NUM_ARROWS, 0);
			arrow_angle.assign(NUM_ARROWS, 0);
			arrow_power.assign(NUM_ARROWS, 0);
			RenderLevelUp(deltaTimeSeconds);
		}
		else {
			RenderButterflies(deltaTimeSeconds);
			RenderArcher(deltaTimeSeconds);
			RenderPowerbar(deltaTimeSeconds);
			RenderShurikens(deltaTimeSeconds);
			RenderHP(deltaTimeSeconds);
			RenderScore();
		}
	}
	else
		RenderGameOver();
}

void BowAndArrow::FrameEnd()
{

}

void BowAndArrow::OnInputUpdate(float deltaTime, int mods)
{
	if (window->KeyHold(GLFW_KEY_W)) {
		if (y_archer < ymax_archer) {
			y_archer += archer_speed * deltaTime;
		}
	}

	if (window->KeyHold(GLFW_KEY_S)) {
		if (y_archer > ymin_archer) {
			y_archer -= archer_speed * deltaTime;
		}
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT)) {
		if (power_fill < 1 && loaded_arrow)
			power_fill += deltaTime;
	}
}

void BowAndArrow::OnKeyPress(int key, int mods)
{
	// add key press event
}

void BowAndArrow::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void BowAndArrow::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float sensitivityOY = 0.01f;

		if (window->GetSpecialKeyState() == 0) {
			archer_angle -= sensitivityOY * deltaY;
		}
	}
}

void BowAndArrow::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void BowAndArrow::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
	if (button == GLFW_MOUSE_BUTTON_2 && loaded_arrow) {
		for (int i = 0; i < NUM_ARROWS; i++)
			if (!release_arrow[i]) {
				if (power_fill < 0.3)
					arrow_power[i] = max_power * 0.3;
				else 
					arrow_power[i] = max_power * power_fill;


				release_arrow[i] = true;
				loaded_arrow = false;
				arrow_angle[i] = archer_angle;
				arrow_offset_x[i] = x_archer;
				arrow_offset_y[i] = y_archer;

				break;
			}
		
		power_fill = 0;

	}
}

void BowAndArrow::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void BowAndArrow::OnWindowResize(int width, int height)
{
}
