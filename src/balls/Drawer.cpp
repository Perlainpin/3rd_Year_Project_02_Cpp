#include "pch.h"
#include "Drawer.h"
#include "GameObject.h"

Drawer::Drawer(){}

Drawer::Drawer(HWND hWnd, BYTE* pixels){
	_hWnd = hWnd;
}

Drawer::~Drawer() {}
void Drawer::Draw(std::vector<GameObject*> goList) {}
void Drawer::Clear() {}