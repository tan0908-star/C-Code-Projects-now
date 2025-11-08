
#ifndef AIRPLAY_H
#define AIRPLAY_H

#include <easyx.h>
#include <time.h>
#include <graphics.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// 图形窗口的大小
#define BGWIDTH 400
#define BGHEIGHT 600

// 飞机和子弹大小
#define myairWIDTH 25
#define myairHEIGHT 40
#define enemyairWIDTH 25
#define enemyairHEIGHT 20
#define BulltWIDTH 8
#define BulltHEIGHT 8

// 速度定义
#define heroSpeed 5
#define enemySpeed 5
#define bulletSpeed 8
#define enemyTimeSpace 1000
#define bulletTimeSpace 200

// 节点结构
typedef struct NODE
{
    int x;
    int y;
    int speed;
    struct NODE *next;
} Node;

// 链表结构
typedef struct Linklist
{
    Node *head;
    Node *end;
    int length;
} LL;

// 全局变量声明
extern LL enemylist;
extern LL bulletlist;
extern Node inithero;

// 函数声明
Node *createNode(int x, int y, int speed);
void initlist(LL *list);
void Linklist_insert(LL *list, int x, int y, int speed);
void deleteNode(LL *list, Node *prev, Node *current);
void userKey();
void updateBullet();
void updateAndcreateEnemy();
void judgeCatch(int *score);
int judgeGame();
void delay(int millisec);

#endif