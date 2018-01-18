#pragma once

#include <string>

#include "bmp\RGBColor.h"
#include "bmp\BMPWriter.h"
#include "colorPalette\ColorPalette.h"

class Visualiser {

public:

	static bool visualiseAltitudeMap(std::string filename, 
		unsigned int width,
		unsigned int height,
		float* altMap)
	{
		unsigned long pixelsCount = width * height;
		RGBColor* raster = new RGBColor[pixelsCount];

		for (unsigned long l = 0; l < pixelsCount; l++) {
			ColorPalette::writeColor(raster + l, altMap[l]);
		}

		BMPWriter::writeToFileAsBMP(filename, width, height, raster);

		delete(raster);

		return true;

	};

};
