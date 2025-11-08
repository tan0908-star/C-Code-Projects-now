#include "AirPlay.h"
#include "list.h"

// 全局变量定义
LL enemylist;
LL bulletlist;
Node inithero = {200, 500, heroSpeed, NULL};
int bulletTimer = 0;
int enemyTimer = 0;

void userKey()
{
    if (GetAsyncKeyState('A') & 0x8000)
    {
        inithero.x -= heroSpeed;
        if (inithero.x < 0)
        {
            inithero.x = 0;
        }
    }
    if (GetAsyncKeyState('D') & 0x8000)
    {
        inithero.x += heroSpeed;
        if (inithero.x > BGWIDTH - myairWIDTH)
        {
            inithero.x = BGWIDTH - myairWIDTH;
        }
    }
    if (GetAsyncKeyState('W') & 0x8000)
    {
        inithero.y -= heroSpeed;
        if (inithero.y < 0)
        {
            inithero.y = 0;
        }
    }
    if (GetAsyncKeyState('S') & 0x8000)
    {
        inithero.y += heroSpeed;
        if (inithero.y > BGHEIGHT - myairHEIGHT)
        {
            inithero.y = BGHEIGHT - myairHEIGHT;
        }
    }

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        if (bulletTimer <= 0)
        {
            int bulletX = inithero.x + myairWIDTH / 2 - BulltWIDTH / 2;
            int bulletY = inithero.y;
            Linklist_insert(&bulletlist, bulletX, bulletY, bulletSpeed);
            bulletTimer = bulletTimeSpace;
        }
    }

    if (bulletTimer > 0)
    {
        bulletTimer -= 16;
    }
}

void updateBullet()
{
    Node *prevbullet = NULL;
    Node *currbullet = bulletlist.head;
    while (currbullet != NULL)
    {
        currbullet->y -= currbullet->speed;
        if (currbullet->y < 0)
        {
            Node *nextcurrbullet = currbullet->next;
            deleteNode(&bulletlist, prevbullet, currbullet);
            currbullet = nextcurrbullet;
        }
        else
        {
            prevbullet = currbullet;
            currbullet = currbullet->next;
        }
    }
}

void updateAndcreateEnemy()
{
    if (enemyTimer <= 0)
    {
        int enemyX = rand() % (BGWIDTH - enemyairWIDTH);
        int enemyY = (-enemyairHEIGHT);
        Linklist_insert(&enemylist, enemyX, enemyY, enemySpeed);
        enemyTimer = enemyTimeSpace;
    }

    if (enemyTimer > 0)
    {
        enemyTimer -= 16;
    }

    Node *prevEnemy = NULL;
    Node *currEnemy = enemylist.head;
    while (currEnemy != NULL)
    {
        currEnemy->y += currEnemy->speed;
        if (currEnemy->y > BGHEIGHT)
        {
            Node *nextcurrenemy = currEnemy->next;
            deleteNode(&enemylist, prevEnemy, currEnemy);
            currEnemy = nextcurrenemy;
        }
        else
        {
            prevEnemy = currEnemy;
            currEnemy = currEnemy->next;
        }
    }
}

void judgeCatch(int *score)
{
    Node *a = bulletlist.head;
    Node *prevA = NULL;
    while (a != NULL)
    {
        Node *b = enemylist.head;
        Node *prevB = NULL;
        Node *nextA = a->next;
        int buttledelete = 0;

        while (b != NULL)
        {
            if (a->x < (b->x + enemyairWIDTH) &&
                (a->x + BulltWIDTH) > b->x &&
                a->y < (b->y + enemyairHEIGHT) &&
                (a->y + BulltHEIGHT) > b->y)
            {
                (*score)++;
                deleteNode(&bulletlist, prevA, a);
                buttledelete = 1;

                Node *nextB = b->next;
                deleteNode(&enemylist, prevB, b);
                b = nextB;
                break;
            }
            prevB = b;
            b = b->next;
        }

        if (buttledelete)
        {
            a = nextA;
        }
        else
        {
            prevA = a;
            a = a->next;
        }
    }
}

int judgeGame()
{
    Node *E = enemylist.head;
    Node *prevE = NULL;
    while (E != NULL)
    {
        if (E->x < (inithero.x + myairWIDTH) &&
            (E->x + enemyairWIDTH) > inithero.x &&
            E->y < (inithero.y + myairHEIGHT) &&
            (E->y + enemyairHEIGHT) > inithero.y)
        {
            deleteNode(&enemylist, prevE, E);
            printf("GAME OVER!");
            return 1;
        }
        prevE = E;
        E = E->next;
    }
    return 0;
}

void delay(int millisec)
{
    Sleep(millisec);
}