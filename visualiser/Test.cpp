
#include "Visualiser.h"


int main() {
	
	unsigned int width = 512;
	unsigned int height = 512;


	float* altitudes = new float[width * height];

	float c;

	for (int w = 0; w < width; w++) {
		c = (2.0f * w / width) - 1.0f;
		for (int h = 0; h < height; h++) {
			altitudes[w*height + h] = c;
		}
	}

	Visualiser::visualiseAltitudeMap("gggggggggg.bmp", width, height, altitudes);

	delete(altitudes);



}