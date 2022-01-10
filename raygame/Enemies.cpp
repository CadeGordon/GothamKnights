#include "Enemies.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "HealthComponent.h"
#include "InputComponent.h"
#include <iostream>

void Enemies::start()
{
	Actor::start();

	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));
	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/Freeze.png")));
	m_healthComponent = dynamic_cast<HealthComponent*> (addComponent(new HealthComponent()));
	m_healthComponent->sethealth(10);

	//Set spawn point 
	//Set move speed
	//Set position clamps
	//Set health
}

void Enemies::update(float deltaTime) 
{
	Actor::update(deltaTime);
	//according to the target's position, the enemy will move towards that position according to the enemy's position
	MathLibrary::Vector2 moveDirection = (m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition()) ;
	m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);


	////Add the new velocity to the old position to get the new position
	//MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;
}

void Enemies::onCollision(Actor* actor)
{
	
	int spawn = GetRandomValue(0,4);
	if (spawn == 0)
	{
		
	}
	if (spawn == 1)
	{
		
	}
	if (spawn == 2)
	{
		
	}
	if (spawn == 3)
	{
	
	}
	if (spawn == 4)
	{
		
	}


	//when the enemy collides with the player apply "collision detected" to the command box
	std::cout << "collision detected" << std::endl;
}
