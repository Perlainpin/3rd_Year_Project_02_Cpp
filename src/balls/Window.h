#pragma once
#include "Drawer.h"
#include "GameObject.h"

class GameObject;
class Timer;

class Window {
public:
    std::vector<GameObject*> AllObjects;
    HINSTANCE _hInstance;
    int _nCmdShow;
    HWND _hWnd;
    WNDCLASSEXW _wcex;

    Timer* _timer;

    Window();
    Window(HINSTANCE _hInstance, int _nCmdShow);
    virtual ~Window();

    bool Initialize(HINSTANCE hInstance, int nCmdShow);
    int RunMessageLoop(Drawer* renderer, std::vector<GameObject*> goList);
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    bool RegisterWindow(HINSTANCE hInstance, int nCmdShow);
    bool CreateAppWindow(HINSTANCE hInstance, int nCmdShow);

};


