#pragma once

class Surface
{
public:

	FILE* pFile{};

	BYTE* _buffer;

	BITMAPFILEHEADER _fileHeader;
	BITMAPINFOHEADER _infoHeader;

	BYTE* _bgr;
	long _lSize;

	Surface();
	virtual ~Surface();

	virtual void LoaderOfBitmap(const char* WfilePath);
	BYTE* BgrToBgra(BYTE* bgr, int width, int height);
	BYTE* BgraToRgba(BYTE* bgra, int width, int height);

};
