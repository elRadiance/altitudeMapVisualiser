#pragma once

#include "BitmapFileHeader.h"
#include "BitmapInfo.h"

struct BMPImageHeader {

	static bool isRowPaddingNeeded(unsigned int width) {
		return !((width * 3) % 4 == 0);
	}

	static unsigned char calculateRowPadding(unsigned int width) {
		return 4 - (width * 3) % 4;
	}

	const BitmapFileHeader bitmapFileHeader;
	const BitmapInfo bitmapInfo;

	/*
		Raster data must be represented in 24-bit format (3 bytes per pixel)
	*/
	BMPImageHeader(unsigned short width, unsigned short height) :
		bitmapFileHeader(sizeof(BitmapFileHeader) + sizeof(BitmapInfo) + (width * height * 3) + calculateRowPadding(width)*height,
			sizeof(BitmapFileHeader) + sizeof(BitmapInfo)),
		bitmapInfo(width, height){}
};
