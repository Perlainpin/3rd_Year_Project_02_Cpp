#pragma once
#include "Window.h"

class WindowSFML : public Window
{
public:

    WindowSFML(HINSTANCE hInstance, int nCmdShow);
    virtual ~WindowSFML();

    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};


