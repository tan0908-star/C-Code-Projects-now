#ifndef LIST_H
#define LIST_H

#include "AirPlay.h"

// 链表操作函数实现
Node *createNode(int x, int y, int speed)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("结点内存分配失败\n");
    }
    node->x = x;
    node->y = y;
    node->speed = speed;
    node->next = NULL;
    return node;
}

void initlist(LL *list)
{
    list->end = NULL;
    list->head = NULL;
    list->length = 0;
}

void Linklist_insert(LL *list, int x, int y, int speed)
{
    Node *newnode = createNode(x, y, speed);
    if (list == NULL)
    {
        return;
    }
    if (list->head == NULL)
    {
        list->head = list->end = newnode;
    }
    else
    {
        list->end->next = newnode;
        list->end = newnode;
    }
    list->length++;
}

void deleteNode(LL *list, Node *prev, Node *current)
{
    if (current == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        list->head = current->next;
        if (list->end == current)
        {
            list->end = NULL;
        }
    }
    else
    {
        prev->next = current->next;
        if (list->end == current)
        {
            list->end = prev;
        }
    }
    free(current);
    list->length--;
}

#endif