#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::start()
{
	Actor::start();


	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	m_moveComponent = dynamic_cast<MoveComponent*> (addComponent(new MoveComponent()));

	m_moveComponent->setMaxSpeed(10);

	m_spriteComponent = dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("Images/bullet.png")));

}

void Bullet::update(float deltaTime)
{
	Actor::update(deltaTime);

	MathLibrary::Vector2 moveDirection = m_inputComponent->getMoveAxis();



	m_moveComponent->setVelocity(moveDirection * 500);
}
