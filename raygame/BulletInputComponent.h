#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>

class BulletInputComponent :
	public Component
{
public:
	BulletInputComponent(const char* name = "InputComponent") : Component::Component(name) {}

	MathLibrary::Vector2 getMoveAxis();
};

