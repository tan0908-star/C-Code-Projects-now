#include "AirPlaystar.h"
#include "AirPlay.h"
int main()
{
    int socre = 0;
    star();
    while (!judgeGame())
    {
        userKey();
        updateBullet();
        updateAndcreateEnemy();
        judgeCatch(&socre);
        judgeGame();
        rander();
        delay(16);
    }
    printf("游戏结束！\n");
    printf("得分：%d", socre);
    closegraph();

    return 0;
}