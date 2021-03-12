#include<stdio.h>
#include<ctime>
#include<stdlib.h>
#include<iostream>
int main()
{
    int N;
    freopen("test1", "w", stdout);
    time_t t;
    srand((unsigned)time(&t));
    scanf("%d", &N);//输入数据组数;
    while (N--)
    {
        int n = rand()%7+4, m = rand()%6+25, T = rand()%12, t1 = rand()%5+1, t2 = rand()%7+5, t3 = rand()%11+3;
        int k = rand()%100+1;
        int ge = rand() % 8 + 1;//名字长度
        printf("%d %d 0%d %d %d %d %d\n", n, m, T, t1, t2, t3, k);
        for (int i = 1; i <= k; i++)
        {
            printf("%c", rand() % 26 + 'A');
            for (int j = 2; j <= ge; j++)
                printf("%c", rand() % 26 + 'a');
            printf("\n%d %d\n", k-i+5,rand()%19+3,rand()%13+2);
        }
    }
    return 0;
}