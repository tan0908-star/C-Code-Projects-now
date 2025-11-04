#include <graphics.h>
#include <conio.h>

int main()
{
    initgraph(400, 300, EX_SHOWCONSOLE); // 初始化400x300的窗口
    putpixel(200, 150, RED);             // 在窗口中心画一个红点
    getch();                             // 等待按键（防止窗口闪退）
    closegraph();
    return 0;
}
