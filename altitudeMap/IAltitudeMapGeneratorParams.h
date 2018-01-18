#pragma once
class IAltitudeMapGeneratorParams {
public: 
	/**
		Implementation must provide unique 64-bit world identifier. 
		This identifier will be used insted of any random during 
		the world altitude map generation
	**/
	virtual long long getWorldId();

	/**
		Implementation must provide float number in range [0.0-1.0].
		0.0 - absolute flat world (minimal altitude change only for oceans zone) 
		0.5 - usual value. Result should be nearly like Earth planet altitude map.
		1.0 - extra-huge amount of mountains. extra deep oceans.
	**/
	virtual float getDegreeOfSurfaceSmoothness();

	/**
		Implementation must provide float number in range [0.0-1.0]
		Overall share of Oceans area.
	**/
	virtual float getPercentageOfWaterSurface();

	/**
		Implementation must provide world map "width" in "pixels"
	**/
	virtual int getSizeX();
	
	/**
		Implementation must provide world map "height" in "pixels"
	**/
	virtual int getSizeY();

	/**
		Implementation must provide world map generation mode (squire or spherical)
	**/
	virtual bool isSphericalMode();
};