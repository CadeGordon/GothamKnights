#include "Player.h"
#include "InputComponent.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "Bullet.h"
#include "Engine.h"


void Player::start()
{
	Actor::start();

	
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));

	m_moveComponent->setMaxSpeed(10);
	
	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/player.png")));
	

	//Set spawn point 
	//Set move speed
	//Set position clamps
}

void Player::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();

	if (m_inputComponent->getSpacePress())
	{
		Scene* currentScene = Engine::getCurrentScene();
		Bullet* bullet = new Bullet(this, 500, getTransform()->getForward(), getTransform()->getLocalPosition().x, getTransform()->getLocalPosition().y);
		bullet->getTransform()->setScale({ 50, 50 });
		currentScene->addActor(bullet);
	}

	

	m_moveComponent->setVelocity(moveDirection * 500);
	
}
