#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>

class GameState;

class Lives : public GameObject
{
	int lives;

public:

	Lives(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
		lives = 5;
	}

	void setLives() {
		lives = 5;
	}

	int getLives() const {
		return lives;
	}

	void update(float dt)
	{
	}

	void init()
	{

	}

	void dec_lives() {
		lives--;
	}


	void draw()
	{
		string text = "Lives: " + to_string(lives);
		graphics::Brush br;

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.2f;
		br.fill_color[2] = 0.2f;
		br.fill_opacity = 1.0;


		graphics::drawText(x, y, 30, text, br);
	}
};