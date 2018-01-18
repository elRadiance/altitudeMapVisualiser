#pragma once
#include <memory>
#include "IAltitudeMap.h"

class IAltitudeMapGenerator {
public:
	virtual IAltitudeMap createMap();
};