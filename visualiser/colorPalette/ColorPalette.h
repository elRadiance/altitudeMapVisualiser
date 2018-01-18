#pragma once

#include <math.h> 

#include "./../bmp/RGBColor.h"


class ColorPalette {

private:
	
	const struct PaletteHolder
	{
		// Landscape colors count 
		static const int COLORS_COUNT_LANDSCAPE;
		
		// Ocean colors count
		static const int COLORS_COUNT_OCEAN;

		static const RGBColor OCEAN_COLORS[7];
		static const RGBColor LANDSCAPE_COLORS[20];

	};

	template <typename T>
	static T clamp(const T& value, const T& min, const T& max) {
		return value <= min ? min : value >= max ? max : value;
	}

	static unsigned char mix(unsigned char left, unsigned char right, float delta) {
		return left + (right - left) * delta;
	}

	static void mix(const RGBColor* colorLeft,
		const RGBColor* colorRight,
		float fromLeftToRightPosition,
		RGBColor* destination) {
		destination->red = mix(colorLeft->red, colorRight->red, fromLeftToRightPosition);//colorRight->red;// +(colorRight->red - colorLeft->red) * fromLeftToRightPosition;
		destination->green = mix(colorLeft->green, colorRight->green, fromLeftToRightPosition);//colorRight->green;// +(colorRight->green - colorLeft->green) * fromLeftToRightPosition;
		destination->blue = mix(colorLeft->blue, colorRight->blue, fromLeftToRightPosition);//colorRight->blue;// +(colorRight->blue - colorLeft->blue) * fromLeftToRightPosition;
	}


public:

	static void writeColor(RGBColor* dest, float altitude) {

		const RGBColor* color0;
		const RGBColor* color1;
		float interpolationDelta, interpolationPosition;
		int colorsCount;

		if (altitude < 0.0f) {
			// Ocean
			colorsCount = ColorPalette::PaletteHolder::COLORS_COUNT_OCEAN;
			interpolationPosition = (altitude + 1.0f) * (colorsCount - 1);
			color0 = &(ColorPalette::PaletteHolder::OCEAN_COLORS[(int)interpolationPosition]);
			color1 = &(ColorPalette::PaletteHolder::OCEAN_COLORS[(int)(interpolationPosition + 1.0f)]);
			interpolationDelta = interpolationPosition - (int)interpolationPosition;

			return mix(color0, color1, interpolationPosition, dest);
		}
		else {
			// Landscape
			colorsCount = ColorPalette::PaletteHolder::COLORS_COUNT_LANDSCAPE;
			interpolationPosition = altitude * (colorsCount - 1);
			color0 = &(ColorPalette::PaletteHolder::LANDSCAPE_COLORS[(int)interpolationPosition]);
			color1 = &(ColorPalette::PaletteHolder::LANDSCAPE_COLORS[(int)(interpolationPosition + 1.0f)]);
			interpolationDelta = interpolationPosition - (int)interpolationPosition;

			return mix(color0, color1, interpolationPosition, dest);
		}
	}

};

// Colors for altitude >= 0.0f (altitude rises with index)
const int ColorPalette::PaletteHolder::COLORS_COUNT_LANDSCAPE = 20;

// Colors for altitude < 0.0f (depth rises with index)
const int ColorPalette::PaletteHolder::COLORS_COUNT_OCEAN = 7;

const RGBColor ColorPalette::PaletteHolder::OCEAN_COLORS[7] = {
	RGBColor(5,56,126),
	RGBColor(9,92,206),
	RGBColor(15,139,199),
	RGBColor(8,161,219),
	RGBColor(51,192,228),
	RGBColor(134,216,237),
	RGBColor(221,240,247)
};

const RGBColor ColorPalette::PaletteHolder::LANDSCAPE_COLORS[20] = {
	RGBColor(0,127,0),
	RGBColor(75,167,37),
	RGBColor(130,207,75),
	RGBColor(151,212,85),
	RGBColor(176,217,95),
	RGBColor(215,228,107),
	RGBColor(255,239,130),
	RGBColor(252,231,122),
	RGBColor(248,223,120),
	RGBColor(236,190,119),
	RGBColor(225,157,95),
	RGBColor(215,141,85),
	RGBColor(205,125,76),
	RGBColor(195,110,63),
	RGBColor(184,95,51),
	RGBColor(173,86,35),
	RGBColor(163,67,19),
	RGBColor(135,54,16),
	RGBColor(106,44,13),
	RGBColor(69,28,7)
};





