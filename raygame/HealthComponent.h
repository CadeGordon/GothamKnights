#pragma once
#include "Component.h"

class HealthComponent :
	public Component
{
public:
	HealthComponent(const char* name = "HealthComponent") : Component::Component(name) {}

	int gethealth() { return m_health; }

	void sethealth(float health) { m_health = health; }

	void update();
private:
	int m_health;
};

