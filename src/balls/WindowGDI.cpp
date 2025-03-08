#include "pch.h"
#include "WindowGDI.h"


WindowGDI::WindowGDI(HINSTANCE hInstance, int nCmdShow)
{
    _hInstance = hInstance;
    _nCmdShow = nCmdShow;
}

WindowGDI::~WindowGDI()
{

}

LRESULT CALLBACK WindowGDI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND: {
        int id = LOWORD(wParam);
        int notif = HIWORD(wParam);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // Add painting code here
        EndPaint(hWnd, &ps);
        break;
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