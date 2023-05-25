#pragma once

class Player
{
private:
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 10;

public:
	void StatusRender();
	void DamagePrint(const char* const _AttName, int _Att);
	void Damage(int _Att);
	const char* GetName();
	int GetAtt();
	bool IsDeath();
};

