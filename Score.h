#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>

class GameState;

class Score : public GameObject
{
	int score;

public:

	Score(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
		score = 0;
	}
	void setScore() {
		score = 0;
	}

	void update(float dt)
	{
	}

	void init()
	{

	}

	void inc_score() {
		score++;
	}


	void draw()
	{
		string text = "SCORE: " + to_string(score);
		graphics::Brush br;

		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0;


		graphics::drawText(x, y, 30, text , br);
	}
};