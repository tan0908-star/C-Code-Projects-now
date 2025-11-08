// #include <stdio.h>
// #include <easyx.h>
// #include <conio.h>

// void drawShap()
// {
//     // 绘制一个点
//     putpixel(50, 50, RED);
//     // 绘制一条线
//     // 设置线条颜色（可选，默认白色）
//     setlinecolor(BLUE);
//     // 设置线条的样式
//     setlinestyle(PS_SOLID, 5); // PS_SOID表示样式，‘5’表示粗细
//     // line(0, 0, getwidth(), getheight());
//     // 绘制一个圆
//     circle(200, 200, 50);
//     fillcircle(500, 500, 50);
//     // 绘制一个椭圆
//     ellipse(200, 0, 50, 300);
//     // 绘制一个正矩形
//     rectangle(100, 10, 150, 60); // （无填充矩形）只需要知道矩形的左上角的坐标和右下角的坐标即可
//     // 设置填充颜色
//     setfillcolor(YELLOW);             // 可选默认为白色,且会对后续图形生效
//     fillrectangle(150, 10, 200, 60);  // （有填充矩形）
//     solidrectangle(205, 10, 255, 60); // 无边框矩形
//     // 绘制一个圆角矩形
//     roundrect(50, 100, 100, 150, 10, 10);
//     // 绘制折线
//     POINT points[] = {{0, 0}, {20, 20}, {50, 80}, {10, 60}};
//     polyline(points, 4);
// }

// void drawTest()
// {
//     const char ch[12] = "Hello World";

//     printf("Hello! Easyx!");
//     outtextxy(10, 10, (const char *)ch);
// }
// int main()
// {
//     // 创建一个图形窗口 宽度*高度
//     initgraph(640, 480, EX_SHOWCONSOLE); // 第三个参数EX_SHOWCONSOLE是为了执行时不仅可以生成一个easyx的图形窗口，而且在终端会显示代码中printf输出内容以及要输入的内容
//     // initgraph(640, 480, EX_NOCLOSE);//EX_NOCLOSE使得图形窗口没有关闭按钮
//     // initgraph(640, 480, EX_NOCLOSE | EX_SHOWCONSOLE | EX_NOMINIMIZE); // 图形窗口既没有关闭按钮也没有最小化按钮

//     // 设置窗口背景颜色
//     setbkcolor(RED);
//     // 用设置的背景颜色填充整个窗口
//     cleardevice();
//     // 窗口的坐标体系：窗口的左上角是坐标原点
//     drawShap();
//     drawTest();
//     getchar();
//     return 0;
// }
