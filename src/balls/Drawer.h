#pragma once
#include "Surface.h"
class GameObject;

class Drawer {
public:
	Drawer();
	Drawer(HWND hWnd, BYTE* pixels);
	virtual ~Drawer();
	virtual void Draw(std::vector<GameObject*> goList);
	virtual void Clear();

	HWND _hWnd;
};