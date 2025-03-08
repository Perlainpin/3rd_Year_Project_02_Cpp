#include "pch.h"
#include "Factory.h"
#include "WindowSFML.h"
#include "WindowGDI.h"
#include "DrawerGDI.h"
#include "DrawerSFML.h"
#include "SurfaceSFML.h"
#include "SurfaceGDI.h"

Factory::Factory() {}
Factory::~Factory() {}

 Window* Factory::BuildWindow(HINSTANCE hInstance, int nCmdShow) {
    #ifdef _SFML
        Window* windowsfml = new WindowSFML(hInstance, nCmdShow);
        windowsfml->Initialize(hInstance, nCmdShow);
        return windowsfml;
    #endif // _SFML
    #ifndef _SFML
        Window* windowgdi = new WindowGDI(hInstance, nCmdShow);
        windowgdi->Initialize(hInstance, nCmdShow);
        return windowgdi;
    #endif // !_SFML
}

Drawer* Factory::BuildDrawer(HWND hWnd,BYTE* bgr, BITMAPINFOHEADER infoHeader) {
    #ifdef _SFML
        Drawer* drawersfml = new DrawerSFML(hWnd,bgr, infoHeader);
        return drawersfml;
    #endif // _SFML
    #ifndef _SFML
        Drawer* drawergdi = new DrawerGDI(hWnd,bgr, infoHeader);
        return drawergdi;
    #endif // !_SFML
}

Surface* Factory::BuildTexture() {
#ifdef _SFML
    TextureSFML* surfacesmfl = new TextureSFML();
    return surfacesmfl;
#endif // _SFML
#ifndef _SFML
    SurfaceGDI* surfacegdi = new SurfaceGDI();
    return surfacegdi;
#endif // !_SFML
}