#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class Alien1 : public GameObject
{

public:
	
	
	
	Alien1(GameState* gs, const std::string& name, int x, int y) : GameObject(gs, name) 
	{
		
		this->x = x;
		this->y = y;
		//this->start_x = x;         // Αποθήκευση αρχικών συντεταγμένων
		//this->start_y = y;
	}

	bool hit_flag = false;
	//float respawn_timer = 0.0f;    // Χρόνος επανεμφάνισης
	//float respawn_delay = 3.0f;    // Καθυστέρηση σε δευτερόλεπτα
	//float start_x, start_y;        // Αρχικές θέσεις

	
	void update(float dt)
	{
		

		x = x - 3;
		// an exei vgei ektos othonis paei stin arxi kai se tyxaio ypso
		if (x < 0) 
		{
			x = 1000;
			y = 450;
			//y = rand() % 800;
			hit_flag = false;
		}

		if (hit_flag)
		{
			x = 2500;      // Αρχική θέση X
			y = 450;       // Αρχική θέση Y
			hit_flag = false; // Επαναφορά της σημαίας σε false για επόμενη επαφή
		}
		
	}

	//void respawn()                 // Μέθοδος για επαναφορά
	//{
	//	x = start_x;
	//	y = start_y;
	//	hit_flag = false;          // Απενεργοποίηση flag
	//	respawn_timer = 0.0f;      // Επαναφορά χρονόμετρου
	//}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;

		br.texture = "assets/alien1.png";
		
		br.outline_opacity = 0.0f;

		graphics::drawRect(x, y, 60, 60, br);
	}
};