#include "Enemies.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "HealthComponent.h"
#include "InputComponent.h"

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

	MathLibrary::Vector2 moveDirection = (m_target->getTransform()->getLocalPosition() - getTransform()->getLocalPosition()).normalize;

	m_moveComponent->setVelocity(moveDirection * 500);


	////Add the new velocity to the old position to get the new position
	//MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;
}
