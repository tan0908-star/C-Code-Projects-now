// 编程练习
// 1.使用嵌套循环
// #include <stdio.h>
// int main()
// {
//     int n;
//     printf("请输入打印行数：\n");
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < i + 1; j++)
//         {
//             printf("$");
//         }
//         printf("\n");
//     }

//     return 0;
// }
//========================================================
// 2.
// #include<stdio.h>
// int main(){
//     char a[]={'A','B','C','D','E','F'};
//     int n=sizeof(a)/sizeof(a[0]);
// for(int i=0;i<n;i++){
//     for(int j=0;j<i+1;j++){
//         printf("%c",a[j]);
//     }
//     printf("\n");
// }return 0;
// }
//========================================================
// 3.
// #include <stdio.h>
// int main()
// {
//     printf("输入大写字母：\n");
//     char ch, l, count;
//     // scanf("%c", &ch);
//     l = ch = 'A';
//     // char count = ch;
//     for (int j = 1; j <= 5; j++)
//     {
//         for (int i = 5 - j; i >= 0; i--)
//         {
//             printf(" ");
//         }

//         for (; l < ch + j; l++)
//         {

//             printf("%c", l);
//             count = l;
//         }
//         l = ch;
//         for (char k = count; k > ch; k--)
//         {
//             printf("%c", k - 1);
//         }
//         printf("\n");
//     }
//     return 0;
// }
//========================================================
// 求最大公约数
// 1.如果b=0，那么a就为最大公约数否则
// 2.让a/b，得到余数赋值给t，随后把b赋值给a，b的值变为t
// 3.回到第一步
// a   b    t
// 12  18   12
// 18  12   6
// 12  6    0
// 6   0
// b=0，最大公约数为6
// #include <stdio.h>
// int main()
// {
//     int a, b, t;
//     scanf("%d %d", &a, &b);
//     if (b == 0)
//     {
//         printf("最大公约数为%d", a);
//     }
//     while (b != 0)
//     {
//         t = a % b;
//         a = b;
//         b = t;
//         if (b == 0)
//         {
//             printf("最大公约数为%d", a);
//             break;
//         }
//     }
//     return 0;
// }
//========================================================
// 给定不超过6的正整数A,考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数。
//*输入格式:
// 输入在一行中给出A。
//*输出格式:
// 输出满足条件的的3位数,要求从小到大,每行6个整数。整数间以空格分隔,但行末不能有多余空
// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int a, i, j, k, cnt = 0;
//     printf("请输入正整数a:\n");
//     scanf("%d", &a);

//     i = a;
//     while (i <= a + 3)
//     {
//         j = a;
//         while (j <= a + 3)
//         {
//             k = a;
//             while (k <= a + 3)
//             {
//                 if (i != j && i != k && j != k)
//                 {

//                     cnt++;
//                     printf("%d%d%d", i, j, k);
//                     if (cnt == 6)
//                     {
//                         printf("\n");
//                         cnt = 0;
//                     }
//                     else
//                         printf(" ");
//                 }
//                 k++;
//             }
//             j++;
//         }
//         i++;
//     }
// }
//========================================================
// 通过函数封装思想和指针遍历的方法重写了上一题
#include <stdio.h>
int isUnique(int i, int j, int k)
{
    if (i != j && i != k && j != k)
    {
        return 1;
    }
    else
        return 0;
}
void OutNoSameCombine(int *nums, int *result, int *count)
{
    *count = 0;
    for (int *p = nums; p <= nums + 3; p++)
    {
        int i = p - nums;
        for (int *q = nums; q <= nums + 3; q++)
        {
            int j = q - nums;
            for (int *m = nums; m <= nums + 3; m++)
            {
                int k = m - nums;
                if (isUnique(i, j, k))
                {
                    int num = *p * 100 + *q * 10 + *m;
                    result[*count] = num;
                    (*count)++;
                }
            }
        }
    }
}
void printfResult(int *result, int *count)
{
    int cnt = 0;
    for (int *p = result; p < result + *count; p++)
    {
        printf("%d", *p);
        cnt++;
        if (cnt == 6)
        {
            printf("\n");
            cnt = 0;
        }
        else
            printf(" ");
    }
}
int main()
{
    int a, i = 0;
    scanf("%d", &a);

    int nums[4]; // 指针若是初始化为0/null，那么后续更改会试图向null的地址写入内容，会触发内存访问错误！
    int *n = nums;
    for (; i <= 3; i++)
    {
        nums[i] = a + i;
    }
    int count;
    int result[24];
    OutNoSameCombine(nums, result, &count);
    printfResult(result, &count);
    return 0;
}
