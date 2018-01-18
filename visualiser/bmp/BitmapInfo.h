#pragma once

#pragma pack(push, 1)
struct BitmapInfo {

	// specifies the size of the BITMAPINFOHEADER structure, in bytes
	const unsigned int biSize = 40; 

	// specifies the width of the image, in pixels.
	const unsigned int biWidth;

	// specifies the height of the image, in pixels.
	const unsigned int biHeight;

	// specifies the number of planes of the target device, must be set to one.
	const unsigned short biPlanes = 1;

	// specifies the number of bits per pixel.
	const unsigned short biBitCount = 24;

	// specifies the type of compression, usually set to zero(no compression).
	const unsigned int biCompression = 0;

	// specifies the size of the image data, in bytes.If there is no compression, it is valid to set this member to zero.
	const unsigned int biSizeImage;

	// specifies the the horizontal pixels per meter on the designated targer device, usually set to zero.
	const unsigned int biXPelsPerMeter = 0;

	// specifies the the vertical pixels per meter on the designated targer device, usually set to zero.
	const unsigned int biYPelsPerMeter = 0;

	// specifies the number of colors used in the bitmap, if set to zero the number of colors is calculated using the biBitCount member.
	const unsigned int biClrUsed = 0;

	// specifies the number of color that are 'important' for the bitmap, if set to zero, all colors are important.
	const unsigned int biClrImportant = 0;

	BitmapInfo(unsigned int width, unsigned int height) 
		: biWidth(width), biHeight(height), biSizeImage(width * height * 3) {}
};
#pragma pack(pop)