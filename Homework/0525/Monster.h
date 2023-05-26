#pragma once

class Monster
{
private:
	char Name[40] = "Monster";
	int Att = 10;
	int Hp = 100;

public:
	void StatusRender();
	void DamagePrint(const char* const _AttName, int _Att);
	void Damage(int _Att);
	const char* GetName();
	int GetAtt();
	bool IsDeath();
};