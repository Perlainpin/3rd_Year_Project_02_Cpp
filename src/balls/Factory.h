#pragma once
#include "Window.h"
#include "Surface.h"
#include "Drawer.h"

class Factory {
public:
	Factory();
	~Factory();

	Window* BuildWindow(HINSTANCE hInstance, int nCmdShow);
	Drawer* BuildDrawer(HWND hWnd, BYTE* bgr, BITMAPINFOHEADER infoHeader);
	Surface* BuildTexture();
};