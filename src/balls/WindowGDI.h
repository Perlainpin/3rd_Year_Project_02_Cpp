#pragma once
#include "Window.h"

class WindowGDI : public Window
{
public:

    WindowGDI(HINSTANCE hInstance, int nCmdShow);
    virtual ~WindowGDI();

    bool Initialize(HINSTANCE hInstance, int nCmdShow);
    int RunMessageLoop();
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool RegisterWindow(HINSTANCE hInstance, int nCmdShow);
    bool CreateAppWindow(HINSTANCE hInstance, int nCmdShow);
};
