#pragma once
#include "Actor.h"
class MoveComponent;
class SpriteComponent;
class HealthComponent;

class Enemies :
	public Actor
{
public:
	Enemies(float x, float y, const char* name, Actor* target) : Actor(x, y, name) { m_target = target; }

	void start() override;
	void update(float deltaTime) override;
	void onCollision(Actor* other) override;

private:
	Actor* m_target;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	HealthComponent* m_healthComponent;
};

