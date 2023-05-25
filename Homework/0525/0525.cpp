// 선생님 프로젝트의 HomeWork0524 프로젝트를 Player, Monster, FightZone을 헤더와 cpp 분리해라
// 헤더와 cpp를 분리해서 이곳에서 동일하게 실행되게 만들어 보세요.

#include "Player.h"
#include "Monster.h"
#include "FightZone.h"

int main()
{
	Player NewPlayer;
	Monster NewMonster;

	FightZone FZone;
	FZone.Fight(NewPlayer, NewMonster);

}
