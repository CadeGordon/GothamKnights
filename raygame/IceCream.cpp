#include "IceCream.h"
#include "MoveComponent.h"
#include "SpriteComponenet.h"
#include "InputComponent.h"
#include "Transform2D.h"
#include "Engine.h"



IceCream::~IceCream()
{
	delete m_inputComponent;
	Actor::~Actor();
}

void IceCream::start()
{
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/red hood.png")));
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	

	Actor::start();
}

void IceCream::update(float deltaTime)
{
	if (GetIsAlive())
	{

		for (int i = 0; i < getTransform()->getChildCount(); i++)
		{
			getTransform()->getChildren()[i]->rotate((PI / 2) * deltaTime);
		}
	}
	else
	{
		Engine::destroy(this);
		for (int i = 0; i < getTransform()->getChildCount(); i++)
		{
			getTransform()->removeChild(i);
		}
	}

	Actor::update(deltaTime);
}

void IceCream::draw()
{
	Actor::draw();
}
