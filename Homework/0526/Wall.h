#pragma once

#include "int4.h"

class Wall : public int4
{
private:
	static const int wallCount = 10;
	int4 ArrWallPos[wallCount]{ {1, 2}, {3, 2}, {4, 5}, {1, 6}, {7, 9}, {15, 2}, {10, 6}, {8, 3}, {18, 2}, {13, 4} };
	char wallCh = 'X';

public:
	Wall();
	int4 GetArrWallPos(int i) const;
	int GetWallCount() const;
	char GetWallCh() const;
};

