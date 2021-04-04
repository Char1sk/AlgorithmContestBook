#include <iostream>
#include <cstring>

bool isPrime[35] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0};

void printArrange(int numbers[20], bool isChoosen[20], int index, int maxN)
{
    if (index == maxN+1)
    {
        if (isPrime[numbers[maxN]+numbers[1]])
        {
            for (int i = 1; i <= maxN; ++i)
            {
                printf("%d%c", numbers[i], (i==maxN ? '\n' : ' '));
            }
        }
    }
    else
    {
        for (int i = 2; i <= maxN; ++i)
        {
            if (!isChoosen[i] && isPrime[numbers[index-1]+i])
            {
                numbers[index] = i;
                isChoosen[i] = true;
                printArrange(numbers, isChoosen, index+1, maxN);
                isChoosen[i] = false;
            }
        }
    }
    
}

int main()
{
    // freopen ("./out.txt", "w", stdout);
    int cases = 0;
    int maxN;
    while (std::cin >> maxN)
    {
        if (cases)
        {
            printf("\n");
        }
        
        int numbers[20];
        bool isChoosen[20];
        memset(isChoosen, 0, sizeof(isChoosen));
        numbers[1] = 1;
        isChoosen[1] = true;
        printf("Case %d:\n", ++cases);
        printArrange(numbers, isChoosen, 2, maxN);
    }
    // bool isPrime[35];
    // memset(isPrime, 1, sizeof(isPrime));
    // printf("{0, 0, ");
    // for (int i = 2; i < 35; ++i)
    // {
    //     for (int j = 2; i*j < 35; ++j)
    //     {
    //         isPrime[i*j] = false;
    //     }
    //     printf("%d, ", isPrime[i]);
    // }
    // printf("}\n");
    return 0;
}