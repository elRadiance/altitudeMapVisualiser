#pragma once
#include "IAltitudeMap.h"

struct AltitudeMapImpl : IAltitudeMap
{
	AltitudeMapImpl(int height, int width) {
		worldHeight = height;
		worldWidth = width;
		altitudes = new float[width * height];
	}

	~AltitudeMapImpl() {
		delete[] altitudes;
	}
};
