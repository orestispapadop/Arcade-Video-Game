#pragma once
#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class BottomLayer : public GameObject
{

public:

	BottomLayer(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {

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

		br.texture = "assets/geology.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 2000, 200, br);
	}
};