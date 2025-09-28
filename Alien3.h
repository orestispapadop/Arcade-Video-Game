#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Alien3 : public GameObject
{

public:

	Alien3(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name)
	{
		
		this->x = x;
		this->y = y;
	}

	bool hit_flag = false;

	void update(float dt)
	{


		x = x + 3;
		// an exei vgei ektos othonis paei stin arxi kai se tyxaio ypso
		if (x > 1000)
		{
			x = -1;
			y = rand() % 400;
			hit_flag = false;
		}

		if (hit_flag)
		{
			x = -200;      // Αρχική θέση X
			y = rand() % 400;       // Αρχική θέση Y
			hit_flag = false; // Επαναφορά της σημαίας σε false για επόμενη επαφή
		}


	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/alien3.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 60, 60, br);
	}
};