#pragma once
#include "Actor.h"
class MoveComponent;
class SpriteComponent;
class HealthComponent;


class Accessory :
	public Actor
{
public:
	Accessory(float x, float y, const char* name) : Actor(x,y,name){}

	void start() override;

	void update(float deltaTime) override;


private:

	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
};

