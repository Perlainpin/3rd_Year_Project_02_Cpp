#include "pch.h"
#include "Surface.h"

Surface::Surface()
{

}

Surface::~Surface()
{
}

void Surface::LoaderOfBitmap(const char* WfilePath)
{

}

BYTE* Surface::BgrToBgra(BYTE* bgr, int width, int height)
{
	int newSize = (width * height) * 4;
	BYTE* newBuffer = new BYTE[newSize];

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			int index24 = (y * width + x) * 3;
			BYTE blue = bgr[index24];
			BYTE green = bgr[index24 + 1];
			BYTE red = bgr[index24 + 2];


			int index32 = (y * width + x) * 4;

			newBuffer[index32] = blue;
			newBuffer[index32 + 1] = green;
			newBuffer[index32 + 2] = red;


			if (red == 255 && green == 0 && blue == 255) {
				newBuffer[index32 + 3] = 0;
			}
			else {
				newBuffer[index32 + 3] = 255;
			}
		}
	}

	return newBuffer;

}
BYTE* Surface::BgraToRgba(BYTE* bgra, int width, int height)
{
	BYTE* rgba = new BYTE[width * height * 4];

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int index = (y * width + x) * 4;
			rgba[index + 2] = bgra[index];
			rgba[index + 1] = bgra[index + 1];
			rgba[index] = bgra[index + 2];
			rgba[index + 3] = bgra[index + 3];
		}
	}

	return rgba;
}
