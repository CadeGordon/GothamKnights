#include "HealthComponent.h"

void HealthComponent::update()
{

	if (gethealth() < 0)
	{
		sethealth(0);
	}
	else
	{
		m_health - 5;
	}
}