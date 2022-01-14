#include "Accessory.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"

void Accessory::start()
{
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/iceCream.png")));
}

void Accessory::update(float deltaTime)
{
	Actor::update(deltaTime);
}
