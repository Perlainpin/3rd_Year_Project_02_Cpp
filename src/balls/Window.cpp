#include "pch.h"
#include "Window.h"
#include "Drawer.h"
#include "Timer.h"

Window::Window()
{

}

Window::Window(HINSTANCE hInstance, int nCmdShow)
{
    _hInstance = hInstance;
    _nCmdShow = nCmdShow;
}

Window::~Window()
{

}

bool Window::RegisterWindow(HINSTANCE hInstance, int nCmdShow) {
    _wcex.cbSize = sizeof(WNDCLASSEX);
    _wcex.style = CS_HREDRAW | CS_VREDRAW;
    _wcex.lpfnWndProc = Window::WndProc;
    _wcex.cbClsExtra = 0;
    _wcex.cbWndExtra = 0;
    _wcex.hInstance = hInstance;
    _wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP));
    _wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    _wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    _wcex.lpszMenuName = nullptr;
    _wcex.lpszClassName = L"WinAppClass";
    _wcex.hIconSm = LoadIcon(_wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&_wcex) != 0;
}

bool Window::CreateAppWindow(HINSTANCE hInstance, int nCmdShow) {
    _hWnd = CreateWindowW(L"WinAppClass", L"Window", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, 0, 814, 839, nullptr, nullptr, hInstance, nullptr);
    if (_hWnd == NULL) {
        MessageBoxA(_hWnd, "problem with hwnd", "box", MB_OK);
        return false;
    }

    ShowWindow(_hWnd, nCmdShow);
    UpdateWindow(_hWnd);

    return true;
}

bool Window::Initialize(HINSTANCE hInstance, int nCmdShow) {
    if (!RegisterWindow(hInstance, nCmdShow)) {
        return false;
    }
    if (!CreateAppWindow(hInstance, nCmdShow)) {
        return false;
    }

    // create and start timer
    _timer = new Timer();
    _timer->Start();

    return true;
}

int Window::RunMessageLoop(Drawer* renderer, std::vector<GameObject*> goList) {
    MSG msg;
    float lastTime = _timer->GetTime();

    // The loop continues while GetMessage returns a value greater than 0
    while (GetMessage(&msg, nullptr, 0, 0) > 0)
    {
        float deltaTime = _timer->GetTime() - lastTime;

        if (deltaTime == 0) // that's an issue
            deltaTime = 1;

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        //// Updating & Rendering ////
        for (int i = 0; i < goList.size(); i++)
        {
            goList[i]->Update(goList, deltaTime);
        }
        renderer->Draw(goList);

        lastTime = _timer->GetTime();
    }

#ifdef _DEBUG
    _CrtDumpMemoryLeaks();
#endif

    return (int)msg.wParam;
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
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
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    }
    return 0;
}
