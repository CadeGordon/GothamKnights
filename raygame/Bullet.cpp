#include "Bullet.h"
#include "MoveComponent.h";
#include "SpriteComponenet.h";
#include "CircleCollider.h"
#include "Engine.h"

Bullet::Bullet(Actor* owner, float speed, MathLibrary::Vector2 direction, float x, float y, const char* name) : Actor::Actor(x, y, name)
{
	m_owner = owner;
	m_bulletSpeed = speed;
	m_bulletDirection = direction;

	m_bulletCollider = new CircleCollider(7, this);
	setCollider(m_bulletCollider);
}

void Bullet::start()
{
	m_spriteComponent = (dynamic_cast<SpriteComponent*>(addComponent(new SpriteComponent("images/Shuriken.png"))));
	m_moveComponent = (dynamic_cast<MoveComponent*>(addComponent(new MoveComponent())));
	m_moveComponent->setMaxSpeed(m_bulletSpeed);

	Actor::start();
}



void Bullet::update(float deltaTime)
{
	m_moveComponent->setVelocity(m_bulletDirection.getNormalized() * m_bulletSpeed);


	Actor::update(deltaTime);
}

//Draws bullet to the screen
void Bullet::draw()
{
	Actor::draw();
	getCollider()->draw();
}

void Bullet::onCollision(Actor* other)
{
	//if the bullets collides with freeze...
	if (other->getName() == "Freeze")
	{
		//...Destroy the bullet
		Engine::destroy(other);
	}
	
}
