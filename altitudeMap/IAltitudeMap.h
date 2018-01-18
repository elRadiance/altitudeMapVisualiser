#pragma once

/*
	Just plain data object, Altitude map data holder.

	Coordinate system (in-plane, 2D):

	Y-axis
	^
	|
	|
	|
	|
	|
	|
	0-------------------> X-axis


*/
struct IAltitudeMap {
	
	/*
		Number of world parts-pixels (chunks) in Y-axis direction	
	*/
	int worldHeight;

	/*
		Number of world parts-pixels (chunks) in X-axis direction
	*/
	int worldWidth;

	/*
		Array of float-values (altitudes). Each value must be in range [-1.0,1.0]
		-1.0 - deepest point in the world below an ocean surface
		0.0 - ocean surface level
		1.0 - highest point of the highest mountain

		Order of altitudes in array must be (for 3x3 array):
		{
			X0Y0 X1Y0 X2Y0
			X0Y1 X1Y1 X3Y1
			X0Y2 X1Y2 X3Y2
		}
		
	*/
	float* altitudes;
};