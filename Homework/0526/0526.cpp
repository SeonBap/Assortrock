// 1. 파일 정리
// 2. 10개의 장애물 배치 class Wall
//    Player 
//    Wall 
//    같은 클래스를 상속받아서 만들어져야 한다.
// 
// 3. 장애물을 통과 못하게 하기.
// 4. 플레이어가 어떠한 키를 누르면 플레이어 위치에서
//    총알 1발이 발사되게 만드세요.

// 5. 그 총알 1발에 벽이 닿으면 벽이 없어지게 만드세요.

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