#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Crane : public GameObject
{

public:

	Crane(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
	}

	bool hit_flag = false;

	void update(float dt)
	{

	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/Crane.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 150, 150, br);
	}
};