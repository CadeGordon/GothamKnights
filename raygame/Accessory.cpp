#include "Accessory.h"
#include "SpriteComponenet.h"
#include "MoveComponent.h"

 void Accessory::start()
{
	Actor::start();

	//sets the sprite to be that of an ice cream cone.
	m_spriteComponent = dynamic_cast<SpriteComponent*> (addComponent(new SpriteComponent("Images/iceCream.png")));

	

}
 void Accessory::update(float deltaTime)
 {
	 Actor::update(deltaTime);
	 //the accessory will move according to the parent's position
	 MathLibrary::Vector2 moveDirection = (getTransform()->getParent()->getLocalPosition());
	 m_moveComponent->setVelocity(moveDirection);

 }
