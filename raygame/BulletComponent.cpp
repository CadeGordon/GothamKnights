#include "BulletComponent.h"
#include "Actor.h"

void BulletComponent::update(float deltaTime)
{
	//Add the new velocity to the old position to get the new position
	MathLibrary::Vector2 newPosition = getOwner()->getTransform()->getLocalPosition() + getVelocity() * deltaTime;

	//Set the actors positoin to be the new position found
	getOwner()->getTransform()->setLocalPosition(newPosition);
}
