#include "pch.h"
#include "main.h"
#include "Factory.h"
#include "GameObject.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    std::vector<GameObject*> balls;
    for (int i = 0; i < 4; i++)
    {
        balls.push_back(new GameObject());
        balls[i]->_posX = 100;
        balls[i]->_posY = 100;
    }

    Factory* factory = new Factory();

    Window* window = factory->BuildWindow(hInstance, nCmdShow);

    HWND hwnd = window->_hWnd;

    Surface* surface = factory->BuildTexture();

    surface->LoaderOfBitmap("../../../src/balls/Texture/Color.bmp");
  
    balls[0]->_speed = 10;
    balls[0]->_bounciness = 1;
    balls[0]->setDirection(-1, -1);
    balls[0]->_posX = 100;
    balls[0]->_posY = 100;
    balls[0]->_speed = 100;
    balls[0]->_bounciness = 1.1f;
    balls[0]->setDirection(0.1f, 0.5f);

    balls[1]->_speed = 10;
    balls[1]->_bounciness = 2.0f;
    balls[1]->setDirection(0.3f, 0.2f);

    balls[2]->_speed = 50;
    balls[2]->_bounciness = 0.9f;
    balls[2]->setDirection(1.2f, -0.2f);

    balls[3]->_speed = 150;
    balls[3]->_bounciness = 1.00001f;
    balls[3]->setDirection(-1.2f, -0.2f);

    GameObject* rect = new GameObject(Shape::square);
    rect->_posX = 10;
    rect->_posY = 10;
    rect->_size = 100;
    balls.push_back(rect);
   
    balls.push_back(rect);

    factory->BuildWindow(hInstance, nCmdShow)->RunMessageLoop(factory->BuildDrawer(hwnd, surface->_bgr, surface->_infoHeader), balls);
}