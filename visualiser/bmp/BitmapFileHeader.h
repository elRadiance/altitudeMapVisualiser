#pragma once

#pragma pack(push, 1)
struct BitmapFileHeader {

	const short bfType = 0x4D42;
	const int bfSize;
	const short bfReserved1 = 0;
	const short bfReserved2 = 0;
	const int bfOffBits;

	BitmapFileHeader(int fileSize, int rasterDataOffset)
		: bfSize(fileSize), bfOffBits(rasterDataOffset){}
};
#pragma pack(pop)