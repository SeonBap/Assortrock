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
}

int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 100;
    char PlayerName[40] = "Player";

    int MonsterHp = 100;
    int MonsterAtt = 10;
    char MonsterName[40] = "Monster";

    while (true)
    {
        // �ܼ�â�� ������ ����� �Լ�
        system("cls");

        // �ѹ��� �Լ��� ������̰�
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        _getch();

        // �ƹ�Ű�� �Է��Ҷ����� ��ٸ��� �Լ�

        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        Damage(MonsterHp, PlayerAtt);
        // MonsterHp -= PlayerAtt;

        _getch();

        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        Damage(PlayerHp, MonsterAtt);

        _getch();

        //if (���� ������)
        //{
        //    return;
        //}


    }
}