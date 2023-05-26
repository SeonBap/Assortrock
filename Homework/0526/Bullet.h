#pragma once

#include "int4.h"

class Bullet
{
private:
	int4 BulletPos;
	int4 MovePos = { 0, 0 };
	bool shot = false;
	bool round = true;

public:
	Bullet();
	int4 GetBulletPos() const;
	void SetBulletPos(const int4& _BulletPos);
	void AddBulletPos(const int4& _BulletPos);
	bool GetShot() const;
	void SetShot(bool _Shot);
	bool GetRound() const;
	void SetRound(bool _Round);
	int4 GetMovePos();
	void SetMovePos();
	void BulletDump();
};

