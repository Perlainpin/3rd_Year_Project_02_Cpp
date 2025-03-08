#include "pch.h"
#include "SurfaceSFML.h"

RenderTextureSFML::RenderTextureSFML()
{
}

RenderTextureSFML::~RenderTextureSFML()
{
}

// ------------------------------------------------------------------------------------------------------------------------------------------------

TextureSFML::TextureSFML()
{
}

TextureSFML::~TextureSFML()
{
}

void TextureSFML::LoaderOfBitmap(const char* WfilePath)
{

	fopen_s(&pFile, WfilePath, "r"); // Ouvrir le fichier BMP en mode binaire
	if (pFile == NULL) {
		return;
	}

	size_t result;

	// Taille du fichier
	fseek(pFile, 0, SEEK_END);
	_lSize = ftell(pFile);
	rewind(pFile);

	// Allocation de la mémoire pour lire le fichier
	_buffer = new BYTE[_lSize];
	if (_buffer == NULL) {
		fclose(pFile);
		return;
	}

	// Lire le fichier dans le buffer
	result = fread(_buffer, 1, _lSize, pFile); // soucis je sais pas pk 
	if (result != _lSize) {
		fclose(pFile);
		delete[] _buffer;
		return;
	}

	// Appliquer les infos du buffer dans les headers
	memcpy(&_fileHeader, _buffer, sizeof(BITMAPFILEHEADER));
	memcpy(&_infoHeader, _buffer + sizeof(BITMAPFILEHEADER), sizeof(BITMAPINFOHEADER));

	// Récupérer les données des pixels (BGR)
	_bgr = _buffer + _fileHeader.bfOffBits;

	_bgr = BgrToBgra(_bgr, _infoHeader.biWidth, _infoHeader.biHeight);
	_bgr = BgraToRgba(_bgr, _infoHeader.biWidth, _infoHeader.biHeight);

	fclose(pFile);
	delete[] _buffer;

}
