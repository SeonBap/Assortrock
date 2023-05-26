#pragma once

#include "Bullet.h"

class ConsoleScreen;

class Player : public Bullet
{
private:
    int4 Pos;

    const int4 Left = { -1, 0 };
    const int4 Right = { 1, 0 };
    const int4 Up = { 0, -1 };
    const int4 Down = { 0, 1 };

public:
    Player();
    Player(const Player&) = delete;
    int4 GetPos() const;
    void SetPos(const int4& _Pos);
    void AddPos(const int4& _Pos);
    void Input(ConsoleScreen* _Screen);
};