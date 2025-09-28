#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Comet : public GameObject
{

public:

	Comet(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name)
	{

		this->x = x;
		this->y = y;
	}

	bool hit_flag = false;

	void update(float dt)
	{


		y = y + 5;
		// an exei ftasei sto edafos paei stin arxi
		if (y > 450)
		{
			//x = 300;
			y = 0;
			x = rand() % 800;
			hit_flag = false;
		}

		if (hit_flag)
		{
			x = 0;      // Αρχική θέση X
			y = rand() % 800;       // Αρχική θέση Y
			hit_flag = false; // Επαναφορά της σημαίας σε false για επόμενη επαφή
		}

	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/comet.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 60, 60, br);
	}
};