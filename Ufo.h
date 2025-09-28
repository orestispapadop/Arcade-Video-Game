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
	//float dt = 0.160f; // ���������� ��� 60 FPS (1/60 = 0.016s)
	float respawn_time = 0.0f;
	//float respawn_timer = 0.0f;  // ���������� �������������
	float respawn_delay = 3.0f;  // ����������� ������������� �� ������������

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
			// ��������� ��� �����������
			respawn_time += dt;

			// ������� �� ���� ������� � ������ �������������
			if (respawn_time >= respawn_delay)
			{
				respawn();  // ������������ UFO
			}
			return; // �� ���� ��������, ��������� ��� ��������� ������
		}
		
	}


	void hide()
	{
		x = -100; // ���������� ����� ������
		y = -100;
		hit_flag = true;
		
	}

	// ������������ UFO �� ������ ����
	void respawn()
	{
		x = rand() % 800;  // ������ ���� X
		y = rand() % 400;  // ������ ���� Y
		hit_flag = false;  // �������������� �������
		
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