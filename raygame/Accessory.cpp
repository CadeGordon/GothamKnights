#include "Accessory.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"

 void Accessory::start()
{
	Actor::start();

	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/iceCream.png")));

	

}
 void Accessory::update(float deltaTime)
 {
	 Actor::update(deltaTime);

	 MathLibrary::Vector2 moveDirection = (getTransform()->getParent()->getLocalPosition());

	 m_moveComponent->setVelocity(moveDirection.getNormalized() * 200);

 }
