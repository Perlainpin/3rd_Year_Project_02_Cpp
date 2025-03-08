#pragma once
#include "Surface.h"

class SurfaceGDI : public Surface
{
public:

	SurfaceGDI();
	virtual ~SurfaceGDI();

	void LoaderOfBitmap(const char* WfilePath);

};
