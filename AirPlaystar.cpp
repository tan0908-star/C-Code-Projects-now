#include "AirPlaystar.h"

// 全局变量定义
IMAGE img[4];

// void init()
// {
//     // 加载图片
//     loadimage(&img[0], "Picture\\AircraftWar\\background.png", BGWIDTH, BGHEIGHT);
//     loadimage(&img[1], "Picture\\AircraftWar\\hero1.png", myairWIDTH, myairHEIGHT);
//     loadimage(&img[2], "Picture\\AircraftWar\\enemy0.png", enemyairWIDTH, enemyairHEIGHT);
//     loadimage(&img[3], "Picture\\AircraftWar\\bullet1.png", BulltWIDTH, BulltHEIGHT);
// }
void init()
{
    // 检查文件是否存在
    FILE *file;

    // 尝试打开文件来检查路径是否正确
    file = fopen("Picture\\AircraftWar\\background.png", "rb");
    if (file == NULL)
    {
        printf("无法找到背景图片文件！\n");
        return;
    }
    fclose(file);

    // 加载图片
    loadimage(&img[0], "Picture\\AircraftWar\\background.png");
    loadimage(&img[1], "Picture\\AircraftWar\\hero1.png");
    loadimage(&img[2], "Picture\\AircraftWar\\enemy0.png");
    loadimage(&img[3], "Picture\\AircraftWar\\bullet1.png");

    printf("图片加载完成！\n");
}
void star()
{
    initgraph(BGWIDTH, BGHEIGHT, EX_SHOWCONSOLE);
    init();
    srand((unsigned)time(NULL));
}

void rander()
{
    putimage(0, 0, &img[0]);
    putimage(inithero.x, inithero.y, &img[1]);

    Node *enemy = enemylist.head;
    while (enemy != NULL)
    {
        putimage(enemy->x, enemy->y, &img[2]);
        enemy = enemy->next;
    }

    Node *bullet = bulletlist.head;
    while (bullet != NULL)
    {
        putimage(bullet->x, bullet->y, &img[3]);
        bullet = bullet->next;
    }
}