#pragma once
#include "Drawer.h"
#include "SurfaceGDI.h"
class GameObject;


class DrawerGDI : public Drawer{
public:
	DrawerGDI(HWND hWnd, BYTE* pixels, BITMAPINFOHEADER infoHeader);
	virtual ~DrawerGDI();
	void Draw(std::vector<GameObject*> goList);
	void Clear(HDC hdc);

	BYTE* _pixels;
	BITMAPINFOHEADER _infoHeader;
};