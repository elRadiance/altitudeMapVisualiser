#pragma once

#pragma pack(push, 1)
struct RGBColor {

	unsigned char blue;
	unsigned char green;
	unsigned char red;

	RGBColor() : blue(0), green(0), red(0) {}

	RGBColor(unsigned char red, unsigned char green, unsigned char blue)
		: blue(blue), green(green), red(red) {}
};
#pragma pack(pop)
