#pragma once
#include "Drawer.h"
#include "SurfaceSFML.h"
class GameObject;


class DrawerSFML : public Drawer{
public:
	DrawerSFML(HWND hWnd, BYTE* pixels, BITMAPINFOHEADER _infoHeader);
	virtual ~DrawerSFML();
	void Draw(std::vector<GameObject*> goList);
	void Clear();

	sf::RenderWindow* _sfmlWindow;
	sf::CircleShape _circle;
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Image _image;
};