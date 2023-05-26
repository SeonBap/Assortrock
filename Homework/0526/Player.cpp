#include <Windows.h>
#include <conio.h>
#include "ConsoleScreen.h"
#include "Player.h"

int4 Player::GetPos() const
{
    return Pos;
}

void Player::AddPos(const int4& _Pos)
{
    Pos += _Pos;
}


void Player::SetPos(const int4& _Pos)
{
    Pos = _Pos;
}

Player::Player(): Pos()
{
}

void Player::Input(ConsoleScreen* _Screen)
{
    if (0 != _kbhit())
    {
        char Select = (char)_getch();

        int4 MovePos = { 0, 0 };

        switch (Select)
        {
        case 'a':
            MovePos = Left;
            break;

        case 'd':
            MovePos = Right;
            break;

        case 'w':
            MovePos = Up;
            break;

        case 's':
            MovePos = Down;
            break;

        case ' ':
            if(false == GetShot() && true == GetRound())
            {
                SetShot(true);
                SetRound(false);
                SetBulletPos(Pos);
                SetMovePos();
            }
            break;

        default:
            break;
        }

        if (false == _Screen->IsScreenOut(GetPos() + MovePos) && _Screen->IsWallBump(GetPos() + MovePos))
        {
            AddPos(MovePos);
        }
    }

    if (true == GetShot() && !(_Screen->IsScreenOut(GetBulletPos() + GetMovePos())))
    {
        AddBulletPos(GetMovePos());
    }

    for (int i = 0; i < _Screen->GetWallCount(); ++i)
    {
        if (_Screen->GetArrWallPos(i).Y == GetBulletPos().Y && _Screen->GetArrWallPos(i).X == GetBulletPos().X)
        {
            SetShot(false);
        }
        else if (_Screen->IsScreenOut(GetBulletPos() + GetMovePos()))
        {
            SetShot(false);
        }
    }


    Sleep(200);
}