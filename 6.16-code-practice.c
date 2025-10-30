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
// 3.
#include <stdio.h>
int main()
{
    printf("输入大写字母：\n");
    char ch, l, count;
    // scanf("%c", &ch);
    l = ch = 'A';
    // char count = ch;
    for (int j = 1; j <= 5; j++)
    {
        for (int i = 5 - j; i >= 0; i--)
        {
            printf(" ");
        }

        for (; l < ch + j; l++)
        {

            printf("%c", l);
            count = l;
        }
        l = ch;
        for (char k = count; k > ch; k--)
        {
            printf("%c", k - 1);
        }
        printf("\n");
    }
    return 0;
}