#include <memory>

#include "IAltitudeMapGeneratorParams.h"
#include "IAltitudeMap.h"
#include "IAltitudeMapGenerator.h"

class AltitudeMapGeneratorImpl : IAltitudeMapGenerator {

	std::shared_ptr<IAltitudeMapGeneratorParams> params;

public:

	AltitudeMapGeneratorImpl(std::shared_ptr<IAltitudeMapGeneratorParams> generatorParams) {
		params = generatorParams;
	}

	virtual IAltitudeMap createMap() {
		// TODO: Implementation!
	}

};