#pragma once
#include "Actor.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"

class InputComponent;
class MoveComponent;
class SpriteComponent;


class Bullet :
	public Actor
{
public:
	Bullet();
	Bullet(float x, float y, const char* name) : Actor(x, y, name) {}
	~Bullet();

	void start() override;
	void update(float deltaTime) override;

private:
	Actor* m_owner;
	MathLibrary::Vector2 m_velocity;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	MathLibrary::Vector2 m_startingPosition;
	MathLibrary::Vector2 m_currentPosition;
	
};

