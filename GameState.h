#pragma once

#include <vector>
#include <chrono> 
#include "GameObject.h"
#include "BottomLayer.h"
#include "SpaceShip.h"
#include "Alien1.h"
#include "Alien2.h"
#include "Alien3.h"
#include "Crane.h"
#include "Ufo.h"
#include "Score.h"
#include "Lives.h"
#include "Comet.h"
#include "Background.h"


using namespace std;

enum class GameStateType
{
	MENU,  // Αρχικό μενού
	GAME,  // Κανονικό παιχνίδι
	RULES,  // Εμφάνιση κανόνων
	GAMEOVER //Game over
};

std::chrono::time_point<std::chrono::steady_clock> lastHitTime = std::chrono::steady_clock::now();

class GameState
{
	private:

		GameStateType currentState = GameStateType::MENU;
		vector <GameObject*> myvec;
		Score* score;
		SpaceShip* s;
		Lives* lives;
		int width = 100;
	

	public:

		GameState() 
		{
			Background *bcgd = new Background(this, "Background", 400, 270);
			myvec.push_back(bcgd);
			BottomLayer *b = new BottomLayer(this, "Bottom Layer", 800, 550);
			myvec.push_back(b);
			Comet* co = new Comet(this, "Comet", 400, 0);
			myvec.push_back(co);
			score = new Score(this, "Score", 350, 70);
			myvec.push_back(score);
			lives = new Lives(this, "Score", 350, 40);
			myvec.push_back(lives);
			Ufo* u = new Ufo(this, "Ufo", 400, 150);
			myvec.push_back(u);
			Crane* c = new Crane(this, "Crane1", 70, 300);
			myvec.push_back(c);
			Crane* c2 = new Crane(this, "Crane2", 730, 300);
			myvec.push_back(c2);
			Alien1 *a = new Alien1(this, "Alien1", 1000, 450);
			myvec.push_back(a);
			Alien2* a2 = new Alien2(this, "Alien2", 1500, 300);
			myvec.push_back(a2);
			Alien3* a3 = new Alien3(this, "Alien3", -1, 150);
			myvec.push_back(a3);
			s = new SpaceShip(this, "Spaceship", 400, 400);
			myvec.push_back( s );
			

		}

		void init() 
		{
		
		}

		void draw()
		{
			if (currentState == GameStateType::MENU)
			{
				drawMenu();
				graphics::Brush br;
				br.texture = "assets/space.png"; // Εικόνα για το μενού
				graphics::drawRect(400,300, 1000, 1000, br);
				lives->setLives();
				score->setScore();
				s->setSpaceShip();
			}
			else if (currentState == GameStateType::GAME)
			{
				
				for (int i = 0; i < myvec.size(); i++)
				{
					myvec[i]->draw();
				}
			}
			else if (currentState == GameStateType::RULES)
			{
				
				graphics::Brush br;
				br.texture = "assets/space.png"; // Εικόνα για το μενού
				graphics::drawRect(400, 300, 1000, 1000, br);
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;

				/*graphics::drawRect(512, 384, 1024, 768, br);*/
				graphics::drawText(260, 200, 50, "GAME RULES", br);
				graphics::drawText(40, 250, 25, "Avoid obstacles and hit enemies using the following buttons.", br);
				graphics::drawText(200, 350, 25, "1. Move: [Up], [Down],[Right],[Left].", br);
				graphics::drawText(230, 400, 25, "2. Destroy enemies: ,[SPACE].", br);
				graphics::drawText(220, 450, 25, "3. Back to Menu: [BACKSPACE]", br);
			}
			else if (currentState == GameStateType::GAMEOVER) {

				graphics::Brush br;
				br.texture = "assets/space.png"; // Αρχείο εικόνας για το Game Over
				//br.texture = "assets/gameover.png"; // Αρχείο εικόνας για το Game Over
				br.outline_opacity = 0.0f;
				graphics::drawRect(400, 300, 1000, 1000, br);

				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
				graphics::drawText(200, 260, 70, "GAME OVER", br);
				graphics::drawText(270, 360, 25, "Play again: [SPACE]", br);
				graphics::drawText(230, 410, 25, "Back to Menu: [BACKSPACE]", br);
			}

		}

		//διαμόρφωση αρχικού μενού
		void drawMenu()
		{
			graphics::Brush br;
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 0.0f;
			br.fill_color[2] = 0.0f;

			graphics::drawRect(512, 384, 1024, 768, br);

			graphics::drawText(70, 200, 45, "WELCOME TO SPAC++E WARS", br);
			graphics::drawText(300, 300, 30, "New Game [1]", br);
			graphics::drawText(290, 350, 30, "Game Rules [2]", br);
			graphics::drawText(320, 400, 30, "Exit [ESC]", br);
		}

		void updateMenu()
		{
			if (graphics::getKeyState(graphics::SCANCODE_1))
			{
				currentState = GameStateType::GAME; // Ξεκινά νέο παιχνίδι
				graphics::playMusic("assets/Star Wars.mp3", 0.5f, true);

			}
			else if (graphics::getKeyState(graphics::SCANCODE_2))
			{
				currentState = GameStateType::RULES; // Εμφάνιση κανόνων
			}
			else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
			{
				graphics::stopMessageLoop(); // Έξοδος από το παιχνίδι
			}
			
		}


		//ενημέρωση κατάστασης παιχνιδιού
		void update(float ms)
		{
			if (currentState == GameStateType::MENU)
			{
				updateMenu();

			}
			else if (currentState == GameStateType::RULES)
			{
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					currentState = GameStateType::MENU; // Επιστροφή στο μενού
				}
			}
			else if (currentState == GameStateType::GAME)
			{

				for (int i = 0; i < myvec.size(); i++)
				{
					myvec[i]->update(ms);
				}

				//Έλεγχος αν το Spacsehip χτυπάει τους εξωγήινους 
				for (int i = 0; i < myvec.size(); i++)
				{
					Alien1* alien1 = dynamic_cast<Alien1*>(myvec[i]);
					if (dynamic_cast<Alien1*>(myvec[i]) != nullptr)
					{

						if (!alien1->hit_flag && s->hit(myvec[i]) == true && graphics::getKeyState(graphics::SCANCODE_SPACE) == true) {
							alien1->hit_flag = true;
							graphics::playSound("assets/killmonster.wav", 1.0f);
							score->inc_score();
						}

					}
				}

				for (int i = 0; i < myvec.size(); i++)
				{
					Alien2* alien2 = dynamic_cast<Alien2*>(myvec[i]);
					if (dynamic_cast<Alien2*>(myvec[i]) != nullptr)
					{

						if (!alien2->hit_flag && s->hit(myvec[i]) == true && graphics::getKeyState(graphics::SCANCODE_SPACE) == true)
						{
							alien2->hit_flag = true;
							graphics::playSound("assets/killmonster.wav", 1.0f);
							score->inc_score();


						}
					}
				}

				for (int i = 0; i < myvec.size(); i++)
				{
					Ufo* ufo = dynamic_cast<Ufo*>(myvec[i]);
					if (dynamic_cast<Ufo*>(myvec[i]) != nullptr)
					{

						if (!ufo->hit_flag && s->hit(myvec[i]) == true && graphics::getKeyState(graphics::SCANCODE_SPACE) == true)
						{
							ufo->hit_flag = true;
							graphics::playSound("assets/killmonster.wav", 1.0f);
							score->inc_score();
						}


						auto now = std::chrono::steady_clock::now();
						auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastHitTime).count();
						
						// Χειρισμός καθυστέρησης επανεμφάνισης
						if (ufo->hit_flag && elapsed >= 2)
						{

							ufo->hit_flag = false;
							lastHitTime = now;
							ufo->respawn();

						}

					}
				}

				for (int i = 0; i < myvec.size(); i++)
				{
					Alien3* alien3 = dynamic_cast<Alien3*>(myvec[i]);
					if (dynamic_cast<Alien3*>(myvec[i]) != nullptr)
					{

						if (!alien3->hit_flag && s->hit(myvec[i]) == true && graphics::getKeyState(graphics::SCANCODE_SPACE) == true)
						{
							alien3->hit_flag = true;
							graphics::playSound("assets/killmonster.wav", 1.0f);
							score->inc_score();
						}
					}
				}

				//Έλεγχος αν το Spacsehip χτυπιέται από αντικείμενα 
				for (int i = 0; i < myvec.size(); i++)
				{
					if (dynamic_cast<Crane*>(myvec[i]) != nullptr)
					{
						auto now = std::chrono::steady_clock::now();
						auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastHitTime).count();

						if (s->crash(myvec[i]) == true) {
							if (elapsed >= 3) 
							{
								lives->dec_lives();   
								graphics::playSound("assets/pulsatings.wav", 1.0f);
								s->isPulsating = true;
								s->pulsateStartTime = std::chrono::steady_clock::now(); // Ενημέρωση χρόνου έναρξης
								lastHitTime = now;    // Ενημέρωση της ώρας τελευταίου χτυπήματος
							}
						}
					}
				}

				for (int i = 0; i < myvec.size(); i++)
				{
					Comet* comet = dynamic_cast<Comet*>(myvec[i]);
					if (dynamic_cast<Comet*>(myvec[i]) != nullptr)
					{

						if (!comet->hit_flag && s->crash(myvec[i]) == true && s->isPulsating == false)
						{
							comet->hit_flag = true;
							graphics::playSound("assets/hit.wav", 1.0f);
							lives->dec_lives();
						}
					}
				}
				if (lives->getLives() == 0) {
					graphics::stopMusic();
					graphics::playSound("assets/SUPER MARIO.mp3", 1.0f);
					currentState = GameStateType::GAMEOVER; // Μετάβαση στην κατάσταση Game Over
					
				}
				
			}
			else if (currentState == GameStateType::GAMEOVER)
			{
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE))
				{
					currentState = GameStateType::MENU; // Επιστροφή στο μενού
				}
				else if (graphics::getKeyState(graphics::SCANCODE_SPACE))
				{
					currentState = GameStateType::GAME; // Ξανα παίξε
					lives->setLives();
					score->setScore();
					s->setSpaceShip();
					graphics::playMusic("assets/Star Wars.mp3", 0.5f, true);
				}
				
			}
		}
		



		~GameState()
		{

			for (int i = 0; i < myvec.size(); i++) 
			{
				delete myvec[i];
			}

		}

		int getWidth() { return width; }
};