#pragma once

#include <iostream>
#include <fstream>

using namespace std;

#include "BMPImageHeader.h"
#include "RGBColor.h"

class BMPWriter {

public :

	/*
		Raster data must be represented in 24-bit format (3 bytes per pixel)
	*/
	static bool writeToFileAsBMP(std::string filename, unsigned int width, unsigned int height, RGBColor* raster) {
		BMPImageHeader image(width, height);
		ofstream file;
		const char paddingBytes[4] = {};
		const unsigned char paddingSize = BMPImageHeader::calculateRowPadding(width);

		file.open(filename, std::ofstream::out | std::ofstream::trunc);
		
		file.write((char*)&image, sizeof(BMPImageHeader));

		for (unsigned int row = 0; row < height; row++) {
			file.write((char*)&raster[row * width], sizeof(RGBColor) * width);

			if (BMPImageHeader::isRowPaddingNeeded(width)) {
				file.write((char*) &paddingBytes, paddingSize);
			}
		}
		
		file.close();

		return true;
	}

};
