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
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/IceCream.png")));
	m_inputComponent = dynamic_cast<InputComponent*>(addComponent(new InputComponent()));
	

	Actor::start();
}

void IceCream::update(float deltaTime)
{
	
}

void IceCream::draw()
{
	Actor::draw();
}
