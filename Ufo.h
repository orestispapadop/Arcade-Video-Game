#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Ufo : public GameObject
{
	int rx = 2;
	int ry = 2;
public:

	Ufo(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) 
	{
		this->x = x;
		this->y = y;
	}

	bool hit_flag = false;
	//float dt = 0.160f; // Παράδειγμα για 60 FPS (1/60 = 0.016s)
	float respawn_time = 0.0f;
	//float respawn_timer = 0.0f;  // Χρονόμετρο επανεμφάνισης
	float respawn_delay = 3.0f;  // Καθυστέρηση επανεμφάνισης σε δευτερόλεπτα

	void update(float dt)
	{
		
		x = x + rx;
		y = y + ry;

		if ( x<30 ) 
		{
			rx = -rx;
		}

		if(x > 770)
		{
			rx = -rx;
		}

		if (y > 450) 
		{
			ry = -ry;
		}
		if (y < 30)
		{
			ry = -ry;

		}

		if (hit_flag)
		{	
			// Ενημέρωση του χρονομέτρου
			respawn_time += dt;

			// Έλεγχος αν έχει περάσει ο χρόνος επανεμφάνισης
			if (respawn_time >= respawn_delay)
			{
				respawn();  // Επανεμφάνιση UFO
			}
			return; // Αν έχει χτυπηθεί, σταματάμε την περαιτέρω κίνηση
		}
		
	}


	void hide()
	{
		x = -100; // Μετακίνηση εκτός οθόνης
		y = -100;
		hit_flag = true;
		
	}

	// Επανεμφάνιση UFO σε τυχαία θέση
	void respawn()
	{
		x = rand() % 800;  // Τυχαία θέση X
		y = rand() % 400;  // Τυχαία θέση Y
		hit_flag = false;  // Απενεργοποίηση σημαίας
		
	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/ufo.png";

		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 70, 70, br);
	}
};