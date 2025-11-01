// 感悟：栈底在操作栈时是不动的，而栈顶要随着入栈和出栈而变化
// 栈顶指针永远指向栈顶元素的下一个位置
#include <stdio.h>
#include <stdlib.h>
typedef int SElemType;
#define STACK_INIT_SIZE 100
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} sqstack;
// 初始化栈
void initstack(sqstack *s)
{
    s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (s->base == NULL)
    {
        exit(-1);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}
// 判断栈是否满
int stackfull(sqstack s)
{
    if (s.top - s.base >= s.stacksize)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 判断栈是否空
int stackempty(sqstack s)
{
    if (s.top == s.base)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void pushstack(sqstack *s, SElemType e)
{
    if (stackfull(*s))
    {
        printf("栈满，无法入栈!\n");
    }
    else
    {
        *(s->top) = e;
        s->top++;
    }
}
void popstack(sqstack *s, SElemType *e)
{
    if (stackempty(*s))
    {
        printf("栈空，无法出栈!\n");
    }
    else
    {
        *e = *(--s->top); // 先栈顶指针减1，再把要出栈的元素赋值给e
    }
}
SElemType gettop(sqstack s)
{
    if (stackempty(s))
    {
        printf("栈空，无法获取栈顶元素!\n");
        return -1;
    }
    else
    {
        return *(s.top - 1);
    }
}
void printfstack(sqstack s)
{
    if (stackempty(s))
    {
        printf("栈空，无法打印栈元素!\n");
    }
    SElemType *p = s.top - 1;
    while (p >= s.base)
    {
        printf("%d", *p);
        p--;
    }
}
void Ten_Change_X()
{
    printf("函数调用中：\n");
    sqstack s;
    initstack(&s); // 该函数调用时要求传入指针类型的栈实例即地址，所以要取地址
    printf("请输入待转换的十进制数m和要转换为几进制n:\n");
    int m, n, x;
    scanf("%d %d", &m, &n);
    while (m != 0)
    {
        pushstack(&s, m % n);
        m /= n;
    }
    if (stackempty(s))
        printf("0");
    while (!stackempty(s))
    {
        popstack(&s, &x);
        printf("%d", x);
    }
    printf("\n");
    free(s.base);
}
int main()
{
    printf("调用数值转换函数\n");
    Ten_Change_X();
    return 0;
}
