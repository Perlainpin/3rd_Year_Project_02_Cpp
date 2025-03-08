#include "pch.h"
#include "WindowSFML.h"


WindowSFML::WindowSFML(HINSTANCE hInstance, int nCmdShow)
{
    _hInstance = hInstance;
    _nCmdShow = nCmdShow;
}

WindowSFML::~WindowSFML()
{

}

LRESULT CALLBACK WindowSFML::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND: {
        int id = LOWORD(wParam);
        int notif = HIWORD(wParam);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }
    default: {
        return Window::WndProc(hWnd, message, wParam, lParam);
    }
    }
    return 0;
}