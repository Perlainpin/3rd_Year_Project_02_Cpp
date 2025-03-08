#pragma once
#include "Surface.h"

class RenderTextureSFML : public Surface
{
public:
	RenderTextureSFML();
	virtual ~RenderTextureSFML();

};

class TextureSFML : public Surface
{
public:

	TextureSFML();
	virtual ~TextureSFML();

	void LoaderOfBitmap(const char* WfilePath);

	sf::Texture _texture;

};
