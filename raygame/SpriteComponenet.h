#pragma once

#include "SpriteComponenet.h"
#include "Component.h"
#include <raylib.h>
#include "Actor.h"


class Texture2D;

class SpriteComponent :
	public Component
{
public:

	/// <param name="texture">Sets the sprites image to be this texture</param>
	/// <param name="name">The name of teh component instacne</param>
	SpriteComponent(Texture2D* texture, const char* name = "SpriteComponent");


	/// <param name="path">The path of the texture to load</param>
	/// <param name="name"></param>
	SpriteComponent(const char* path, const char* name = "SpriteComponent");

	~SpriteComponent() override;

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

	void draw() override;

private:
	Texture2D* m_texture;
	int m_width;
	int m_height;

};
