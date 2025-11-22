#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int date;
    struct Node *next;
} Node;

typedef struct Linklist
{
    struct Node *head;
    struct Node *end;
    int length;
} Linklist;
Node *createNode(int date) // 生成节点
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("内存分配失败！");
    }
    node->date = date;
    node->next = NULL;
    return node;
}
void init_Linklist(Linklist *list)
{
    list->head = NULL;
    list->end = NULL;
    int length = 0;
}
void insert_Linklist_Head(int date, Linklist *list) // 头插法插入节点
{
    Node *node = createNode(date);
    if (list->head == NULL)
    {
        list->head = node;
        list->end = list->head;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
    list->length++;
}
void insert_Linklist_End(int date, Linklist *list) // 尾插法
{
    Node *node = createNode(date);
    if (list->head == NULL)
    {
        list->end = list->head = node;
    }
    else
    {
        list->end->next = node;
        list->end = node;
    }
    list->length++;
}
int deleteNode(int date, Linklist *list) // 删除节点
{
    int isor = 0;
    if (list->head == NULL)
    {
        return isor;
    }
    Node *prev = NULL;
    Node *curr = list->head;
    while (curr)
    {
        if (curr->date == date)
        {
            prev->next = curr->next;
            isor = 1;
            break;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    list->length--;
    free(curr);
    return isor;
}
void printf_Linklist(Linklist *list) // 打印节点
{
    Node *curr = list->head;
    while (curr)
    {
        printf("%d", curr->date);
        printf(" ");
        curr = curr->next;
    }
}
int main()
{
    Linklist list;
    init_Linklist(&list);
    insert_Linklist_Head(4, &list);
    insert_Linklist_Head(3, &list);
    insert_Linklist_Head(2, &list);
    insert_Linklist_Head(1, &list);
    insert_Linklist_End(5, &list);
    insert_Linklist_End(6, &list);
    printf_Linklist(&list);
    int isor = deleteNode(5, &list);
    if (!isor)
        printf("删除失败！");
    printf("\n");
    printf_Linklist(&list);
}