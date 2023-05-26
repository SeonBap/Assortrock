#include <iostream>
#include "ConsoleScreen.h"

ConsoleScreen::ConsoleScreen()
{

}

void ConsoleScreen::Init(char _BaseCh)
{
    BaseCh = _BaseCh;
    Clear();
}

void ConsoleScreen::SetPixel(const int4& _Pos, const int4& _BulletPos, const bool& _GetShot, char _Ch, char _BulletCh)
{
    ArrScreen[_Pos.Y][_Pos.X] = _Ch;

    if (true == _GetShot)
    {
        ArrScreen[_BulletPos.Y][_BulletPos.X] = _BulletCh;
    }
}

void ConsoleScreen::Clear()
{
    system("cls");

    for (size_t y = 0; y < YLine; y++)
    {
        for (size_t x = 0; x < XLine; x++)
        {
            ArrScreen[y][x] = BaseCh;
        }
        ArrScreen[y][XLine] = 0;
    }

    for (int i = 0; i < GetWallCount(); ++i)
    {
        ArrScreen[GetArrWallPos(i).Y][GetArrWallPos(i).X] = GetWallCh();
    }
}

bool ConsoleScreen::IsScreenOut(const int4& _Pos) const
{
    if (0 > _Pos.X)
    {
        return true;
    }

    if (0 > _Pos.Y)
    {
        return true;
    }

    if (XLine <= _Pos.X)
    {
        return true;
    }

    if (YLine <= _Pos.Y)
    {
        return true;
    }

    return false;
}

bool ConsoleScreen::IsWallBump(const int4& _Pos) const
{
    if (ArrScreen[_Pos.Y][_Pos.X] != GetWallCh())
    {
        return true;
    }

    return false;
}

void ConsoleScreen::Print() const
{
    for (size_t y = 0; y < YLine; y++)
    {
        printf_s(ArrScreen[y]);
        printf_s("\n");
    }
}