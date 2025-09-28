#pragma once

#include "GameObject.h"
#include "GameState.h"
#include <sgg/graphics.h>


class SpaceShip : public GameObject
{
	int spaceship;

 public:

	 bool isPulsating = false; // Αν είναι σε κατάσταση παλμού
	 std::chrono::time_point<std::chrono::steady_clock> pulsateStartTime; // Ώρα έναρξης παλμού

	SpaceShip(GameState* gs, const std::string& name, int x, int y) : GameObject(gs,name) {

		this->x = x;
		this->y = y;
	}

	
	void setSpaceShip() {
		this->x = 400;
		this->y = 400;
	}

	

		//// Κανονική ενημέρωση θέσης
		//if (graphics::getKeyState(graphics::SCANCODE_RIGHT) && x < 800) {
		//	x += 3;
		//}
		//if (graphics::getKeyState(graphics::SCANCODE_LEFT) && x > 1) {
		//	x -= 3;
		//}
		//if (graphics::getKeyState(graphics::SCANCODE_UP) && y > 1) {
		//	y -= 3;
		//}
		//if (graphics::getKeyState(graphics::SCANCODE_DOWN) && y < 450) {
		//	y += 3;
		//}
	

	void update(float dt)
	{
		if (isPulsating) {
			// Έλεγχος αν έχουν περάσει 3 δευτερόλεπτα από την έναρξη του παλμού
			auto now = std::chrono::steady_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - pulsateStartTime).count();

			if (elapsed >= 3) {
				isPulsating = false; // Τερματισμός παλμού
			}

		}

		if (graphics::getKeyState( graphics::SCANCODE_RIGHT ) == true) 
		{
				
			if (x < 800)
			{
				x = x + 3;
			}
				
		}
		if (graphics::getKeyState(graphics::SCANCODE_LEFT) == true) 
		{
				
			if (x > 1)
			{
				x = x - 3;
			}
				
		}
		if (graphics::getKeyState(graphics::SCANCODE_UP) == true) 
		{
				
			if (y > 1) 
			{
				y = y - 3;
			}
		}
		if (graphics::getKeyState(graphics::SCANCODE_DOWN) == true) 
		{
				
			if (y < 450)
			{
				y = y + 3;
			}
		}
	}

	void init()
	{

	}

	void draw()
	{
		graphics::Brush br;
		br.texture = "assets/spaceship.png";
		br.outline_opacity = 0.0f;

		if (isPulsating) 
		{
			// Υπολογισμός αλλαγής μεγέθους κατά τη διάρκεια του παλμού
			float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::steady_clock::now() - pulsateStartTime).count() / 1000.0f;
			float scaleFactor = (int(elapsed * 10) % 2 == 0) ? 1.1f : 0.9f; // Εναλλαγή μεγέθους
			graphics::drawRect(x, y, 60 * scaleFactor, 60 * scaleFactor, br);
		}
		else 
		{
			graphics::drawRect(x, y, 60, 60, br);
		}
	}
};