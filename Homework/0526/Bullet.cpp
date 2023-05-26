#include "Bullet.h"

Bullet::Bullet()
{
}

int4 Bullet::GetBulletPos() const
{
    return BulletPos;
}

void Bullet::SetBulletPos(const int4& _BulletPos)
{
    return BulletPos = _BulletPos;
}

void Bullet::AddBulletPos(const int4& _BulletPos)
{
    return BulletPos += _BulletPos;
}

bool Bullet::GetShot() const
{
    return shot;
}

void Bullet::SetShot(bool _Shot)
{
    shot = _Shot;
}

bool Bullet::GetRound() const
{
    return round;
}

void Bullet::SetRound(bool _Round)
{
    round = _Round;
}

int4 Bullet::GetMovePos()
{
    return MovePos;
}

void Bullet::SetMovePos()
{
    MovePos = { 0 , 1 };
}