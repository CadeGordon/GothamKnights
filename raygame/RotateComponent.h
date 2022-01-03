#pragma once
#include "Component.h"
#include <Matrix3.h>
class RotateComponent :
	public Component
{
public:
	MathLibrary::Matrix3 CreateRotation() { return m_rotation;  }
private: 
	MathLibrary::Matrix3 m_rotation;
};

