// 1. ���� ����
// 2. 10���� ��ֹ� ��ġ class Wall
//    Player 
//    Wall 
//    ���� Ŭ������ ��ӹ޾Ƽ� ��������� �Ѵ�.
// 
// 3. ��ֹ��� ��� ���ϰ� �ϱ�.
// 4. �÷��̾ ��� Ű�� ������ �÷��̾� ��ġ����
//    �Ѿ� 1���� �߻�ǰ� ���弼��.

// 5. �� �Ѿ� 1�߿� ���� ������ ���� �������� ���弼��.

#include "ConsoleScreen.h"
#include "Player.h"

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), MainPlayer.GetBulletPos(), MainPlayer.GetShot(), 'a', 'O');
        Screen.Print();

        MainPlayer.Input(&Screen);
    }
}