#include <iostream>
#include <conio.h>

// 숙제 1 -- 문자의 오른쪽끝을 맞춰오세요. 이름은 알파뱃만
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// 위와같이 UI의 끝부분이 맞게 만들어라.

// 숙제 2 -- 실시간으로 만들어오세요.
// 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 만들어라.
// 화면 지우는 함수 화면에 출력하는 함수를 잘 생각해보세요.
// 그냥 무식하게 생각해라.

// 숙제 3 -- 누군가 죽었다. 누군가의 Hp가 0이 된순간 종료.
// 몬스터와 플레이어가 서로 한대씩 때리면서
// 한명이 죽으면 끝납니다.
// if (조건 만족시)
// {
//     return;
// }



void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40개로 맞춰오세요.

    for (int i = 0; i < 40; ++i)
    {
        if (_Name != nullptr && _Name[i] != '\0')
        {
            printf("%c" , _Name[i]);
        }
        else
        {
            printf("-");
        }
    }
    printf("\n");


    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);

    for (int i = 0; i < 40; ++i)
    {
        printf("-");
    }
    printf("\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;

    if (_Hp < 0)
    {
        _Hp = 0;
    }
}

int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 40;
    char PlayerName[40] = "Player";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";

    StatusRender(PlayerName, PlayerAtt, PlayerHp);
    StatusRender(MonsterName, MonsterAtt, MonsterHp);

    // 아무키나 입력할때까지 기다리는 함수
    _getch();


    while (true)
    {
        // 콘솔창을 모조리 지우는 함수
        system("cls");

        Damage(MonsterHp, PlayerAtt);
        
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        // MonsterHp -= PlayerAtt;

        if (MonsterHp == 0)
        {
            return 0;
        }

        _getch();

        system("cls");

        Damage(PlayerHp, MonsterAtt);

        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);

        if (PlayerHp == 0)
        {
            return 0;
        }

        _getch();
    }
}