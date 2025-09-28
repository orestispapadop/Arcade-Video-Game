#pragma once

#include <string>
#include "GameState.h"

using namespace std;


class GameObject
{
	static int m_next_id;
protected:

	class GameState* m_state;
	std::string m_name;
	int m_id = 0;
	bool m_active = true;

	int x, y;
	int count = 0;


public:
	GameObject(GameState* gs, const std::string& name = "") 
	{
		bool hit_flag = false;
		m_state = gs;
		m_name = name;
	}
	
	virtual void update(float dt) {}
	virtual void init() {}
	virtual void draw() {}



	virtual ~GameObject() {}

	bool isActive() { return m_active; }
	void setActive(bool a) { m_active = a; }

	bool hit(GameObject* other) 
	{
		if ((sqrt(pow(x - other->x, 2) + pow(y - other->y, 2)) < 60)) 
		{
			return true;
			
		
		}
		else 
		{
			return false;
		}
	}

	bool crash(GameObject* other)
	{
		if ((sqrt(pow(x - other->x, 2) + pow(y - other->y, 2)) < 85))
		{
			return true;


		}
		else
		{
			return false;
		}
	}
};