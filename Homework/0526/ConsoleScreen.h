#pragma once

#include "ScreenSize.h"
#include "Wall.h"

class ConsoleScreen : public Wall
{
private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};

public:
    ConsoleScreen();
    void Init(char _BaseCh);
    void SetPixel(const int4& _Pos, const int4& _BulletPos, const bool& _GetShot, char _Ch, char _BulletCh);
    void Clear();
    bool IsScreenOut(const int4& _Pos) const;
    bool IsWallBump(const int4& _Pos) const;
    void Print() const;

};