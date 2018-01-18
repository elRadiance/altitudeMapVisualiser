
#include "Visualiser.h"


int main() {
	
	unsigned int width = 512;
	unsigned int height = 512;


	float* altitudes = new float[width * height];

	float c;

	for (unsigned int w = 0; w < width; w++) {
		c = 2.0f * ((float)w) / ((float)width) - 1.0f;
		for (unsigned int h = 0; h < height; h++) {
			altitudes[w*height + h] = c;
		}
	}

	Visualiser::visualiseAltitudeMap("gggggggggg.bmp", width, height, altitudes);

	delete(altitudes);



}