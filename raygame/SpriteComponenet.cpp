#include "SpriteComponenet.h"
#include <raylib.h>
#include "Transform2D.h"
#include "Actor.h"
#include <Matrix3.h>
#include <cmath>



SpriteComponent::SpriteComponent(Texture2D* texture, const char* name) : Component::Component(name)
{
	m_texture = texture;
}

SpriteComponent::SpriteComponent(const char* path, const char* name) : Component::Component(name)
{
	m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
}

SpriteComponent::~SpriteComponent()
{
	RAYLIB_H::UnloadTexture(*m_texture);
	delete m_texture;
	
}

void SpriteComponent::draw()
{   //Gets the scale of the global matrix
	m_width = getOwner()->getTransform()->getScale().x;
	m_height = getOwner()->getTransform()->getScale().y;

	m_texture->width = m_width;
	m_texture->height = m_height;

	//Gets the world positoin of the owner
	MathLibrary::Vector2 up = { getOwner()->getTransform()->getGlobalMatrix()->m01, getOwner()->getTransform()->getGlobalMatrix()->m11 };
	MathLibrary::Vector2 forward = getOwner()->getTransform()->getForward();
	MathLibrary::Vector2 position = getOwner()->getTransform()->getWorldPosition();
	
	//Changes the position of the sprite to be in the center of the transform
	position = position - (forward * getWidth() / 2);
	position = position - (up.getNormalized() * getHeight() / 2);

	//Change the position vector to be a raylib vector
	RAYLIB_H::Vector2 rayPos = { position.x, position.y };

	//Gets the value of rotation in radians from the owner transform
	float rotation = atan2(getOwner()->getTransform()->getLocalMatrix()->m10, getOwner()->getTransform()->getLocalMatrix()->m00);

	//Draw the sprite
	RAYLIB_H::DrawTextureEx(*m_texture, rayPos, (float)(rotation * 180.0f / PI), 1, PINK);
}
