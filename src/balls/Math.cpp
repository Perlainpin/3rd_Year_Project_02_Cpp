#include "pch.h"
#include "Math.h"
#include "GameObject.h"

Math::Math() {};
Math::~Math() {};

void Math::normalize(float* x, float* y) {
	float norm = sqrt(*x * *x + *y * *y);
	if (norm != 0.0f) {
		(*x /= norm);
		(*y /= norm);
	}
}