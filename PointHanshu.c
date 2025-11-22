#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//函数指针以及回调函数
void popular_arry(int *arry, size_t arrysize, int (*p)(void))
{
    for (size_t i = 0; i < arrysize; i++)
    {
        arry[i] = p();
    }
}
int getNextRandomValue()
{
    return rand();
}
int main()
{
    srand((unsigned)time(NULL));
    int myarry[10];
    popular_arry(&myarry[0], 10, getNextRandomValue);//直接写函数名不写括号，因为这里要是函数的地址，而不是加了括号后的函数返回值
    for (size_t j = 0; j < 10; j++)
    {
        printf("%d ", myarry[j]);
    }
    printf("\n");
    return 0;
}