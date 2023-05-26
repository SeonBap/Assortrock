#include <iostream>
#include "Wall.h"
#include "ScreenSize.h"

Wall::Wall()
{
}

int4 Wall::GetArrWallPos(int i) const
{
	return ArrWallPos[i];
}

int Wall::GetWallCount() const
{
	return wallCount;
}

char Wall::GetWallCh() const
{
	return wallCh;
}
