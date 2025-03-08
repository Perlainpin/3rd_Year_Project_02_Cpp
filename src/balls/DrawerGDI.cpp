#include "pch.h"
#include "DrawerGDI.h"
#include "GameObject.h"

DrawerGDI::DrawerGDI(HWND hWnd, BYTE* pixels, BITMAPINFOHEADER infoHeader) {
    _hWnd = hWnd;
    _pixels = pixels;
    _infoHeader = infoHeader;
}

void DrawerGDI::Draw(std::vector<GameObject*> goList) {
    
    if (_hWnd == NULL) {
        return;
    }

    HDC hdc = GetDC(_hWnd);
    HDC BackHdc = CreateCompatibleDC(hdc);
    HDC hDcSprite = CreateCompatibleDC(hdc);

    RECT rect;
    GetClientRect(_hWnd, &rect);

    // Create a compatible bitmap for the back buffer
    HBITMAP hBitmap = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(BackHdc, hBitmap);

    // Create the sprite bitmap from the pixel data with the alpha channel
    HBITMAP SpriteBitmap = CreateDIBitmap(hdc, &_infoHeader, CBM_INIT, _pixels, (BITMAPINFO*)&_infoHeader, DIB_RGB_COLORS);
    HBITMAP hOldSpriteBitmap = (HBITMAP)SelectObject(hDcSprite, SpriteBitmap);

    // Clear the back buffer
    Clear(BackHdc);

    for (int i = 0; i < goList.size(); i++) {
        GameObject* go = goList[i];

        if (go->_shape == Shape::ball) {
            int left = go->_posX;
            int top = go->_posY;

            BLENDFUNCTION blendFunction;
            blendFunction.BlendOp = AC_SRC_OVER;
            blendFunction.BlendFlags = 0;
            blendFunction.SourceConstantAlpha = 255;  // Full opacity (use the sprite's alpha)
            blendFunction.AlphaFormat = AC_SRC_ALPHA; // Use the source image alpha channel

            // Use AlphaBlend to draw the sprite with transparency
            BOOL test = AlphaBlend(
                BackHdc,
                left, top,
                _infoHeader.biWidth, _infoHeader.biHeight,
                hDcSprite,
                0, 0,
                _infoHeader.biWidth, _infoHeader.biHeight,
                blendFunction
            );

            if (!test) {
                // Handle the error if AlphaBlend fails
                // (you can call GetLastError() here if needed)
            }
        }
    }

    // Copy the back buffer to the window
    BitBlt(hdc,
        0, 0,
        rect.right, rect.bottom,
        BackHdc,
        0, 0, SRCCOPY);

    // Cleanup: Select back the old bitmaps and delete the created objects
    SelectObject(BackHdc, hOldBitmap);
    SelectObject(hDcSprite, hOldSpriteBitmap);

    DeleteObject(SpriteBitmap);
    DeleteObject(hBitmap);

    DeleteDC(hDcSprite);
    DeleteDC(BackHdc);

    ReleaseDC(_hWnd, hdc);

}

void DrawerGDI::Clear(HDC hdc) {

    //HDC hdc = GetDC(_hWnd);

    RECT rect;
    GetClientRect(_hWnd, &rect);

    HBRUSH hBrush = CreateSolidBrush(RGB(200, 255, 200));  // Red color
    // Select the brush into the DC
    HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);

    // Clean up the GDI objects
    SelectObject(hdc, hOldBrush);
    DeleteObject(hBrush);
    // Release the device context
    ReleaseDC(_hWnd, hdc);
}

DrawerGDI::~DrawerGDI() {}