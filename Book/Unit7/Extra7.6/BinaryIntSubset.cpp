#include <iostream>

const int maxN = 3;

void printSubset(int arr[maxN], int bin)
{
    for (int i = 0; i < maxN; ++i)
    {
        if (1 & (bin>>i))
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int arr[maxN] = {1, 4, 5};
    for (int i = 0; i < (1<<maxN); ++i)
    {
        printSubset(arr, i);
    }
    return 0;
}