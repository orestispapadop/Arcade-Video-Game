#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Background : public GameObject
{

public:

	Background(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

		this->x = x;
		this->y = y;
	}

	void update(float dt)
	{

	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/space.png";

		graphics::drawRect(x, y, 1000, 1000, br);
	}
};