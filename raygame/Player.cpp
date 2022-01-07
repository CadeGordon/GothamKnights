#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "HealthComponent.h"
#include "Bullet.h"


void Player::start()
{
	Actor::start();

	
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));

	m_moveComponent->setMaxSpeed(10);
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/red hood.png")));
	m_healthComponent = dynamic_cast<HealthComponent*> (addComponent(new HealthComponent()));
	m_healthComponent->sethealth(10);

	//Set spawn point 
	//Set move speed
	//Set position clamps
	//Set health
}

void Player::update(float deltaTime)
{
	
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	if (m_moveComponent->getVelocity().getMagnitude() > 0)
		getTransform()->setForward(m_moveComponent->getVelocity());

	m_moveComponent->setVelocity(moveDirection * 500);

	
}
