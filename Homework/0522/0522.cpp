#include <iostream>
#include <conio.h>

// ���� 1 -- ������ �����ʳ��� ���������. �̸��� ���Ĺ
// fasdhjkfasdhjfkasd--------
// Monster-------------------
// ���Ͱ��� UI�� ���κ��� �°� ������.

// ���� 2 -- �ǽð����� ����������.
// ������ �޼����� �����¼��� ü���� ��ٷ� ���ҵǰ� ������.
// ȭ�� ����� �Լ� ȭ�鿡 ����ϴ� �Լ��� �� �����غ�����.
// �׳� �����ϰ� �����ض�.

// ���� 3 -- ������ �׾���. �������� Hp�� 0�� �ȼ��� ����.
// ���Ϳ� �÷��̾ ���� �Ѵ뾿 �����鼭
// �Ѹ��� ������ �����ϴ�.
// if (���� ������)
// {
//     return;
// }



void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 40���� ���������.

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


    printf_s("���ݷ� : %d\n", _Att);
    printf_s("ü  �� : %d\n", _Hp);

    for (int i = 0; i < 40; ++i)
    {
        printf("-");
    }
    printf("\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s�� %s�� �����߽��ϴ�.\n", _AttName, _DefName);
    printf_s("%s�� %d�� �������� �Ծ����ϴ�.\n", _DefName, _Att);
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

    // �ƹ�Ű�� �Է��Ҷ����� ��ٸ��� �Լ�
    _getch();


    while (true)
    {
        // �ܼ�â�� ������ ����� �Լ�
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