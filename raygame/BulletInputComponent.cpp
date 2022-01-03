#include "BulletInputComponent.h"

MathLibrary::Vector2 BulletInputComponent::getMoveAxis()
{
	
	float bulletDirectionX = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_LEFT) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_RIGHT);
	float bulletDirectionY = -RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_UP) + RAYLIB_H::IsKeyDown(RAYLIB_H::KEY_DOWN);

	//Return a new vector represenitng the move direction
	
	return MathLibrary::Vector2(bulletDirectionX, bulletDirectionY);


}
