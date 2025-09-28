#include <iostream>
#include <sgg/graphics.h>

#include "GameState.h"

GameState game;

void update(float ms)
{
	game.update( ms );
}

void draw()
{
	game.draw();
}

int main()
{
	graphics::createWindow(1024, 768, "SPAC++E WARS");
	



	game.init();

	graphics::Brush br;
	br.fill_color[0] = 0.6f;
	br.fill_color[1] = 0.6f;
	br.fill_color[2] = 0.9f;
	graphics::setWindowBackground(br);


	graphics::setUserData( &game );
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::setCanvasSize(800.0f, 600.0f);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	graphics::setFont("assets/text.ttf");


	graphics::startMessageLoop();
	graphics::destroyWindow();

	return 0;
}
