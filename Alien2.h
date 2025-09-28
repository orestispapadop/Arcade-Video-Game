#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Alien2 : public GameObject
{

public:

	Alien2(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) {
		
		this->x = x;
		this->y = y;
	}

	bool hit_flag = false;

	void update(float dt)
	{

		x = x - 2;

		if (x < 0) {
			x = 1500;
			y = 300;
		}

		if (x < 630) {

			if (y < 450) {
				y = y + 3;
				hit_flag = false;
			}
		}
		
		

		if (hit_flag)
		{
			x = 2000;      // Αρχική θέση X
			y = 300;       // Αρχική θέση Y
			hit_flag = false; // Επαναφορά της σημαίας σε false για επόμενη επαφή
		}
		
	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/alien2.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 60, 60, br);
	}
};