#pragma once
#include "Actor.h"


class InputComponent;
class MoveComponent;
class SpriteComponent;


class IceCream :
    public Actor

{
public:
	IceCream(float x, float y, const char* name) : Actor(x, y, name) {}
	~IceCream();
	

	void start() override;
	void update(float deltaTime) override;
	void draw() override;

private:
	InputComponent* m_inputComponent;
	MoveComponent* m_moveComponent;
	SpriteComponent* m_spriteComponent;
	
};

