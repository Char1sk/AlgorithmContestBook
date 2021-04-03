#include <iostream>

const int maxN = 3;

void printSubset(int arr[maxN], bool judge[maxN], int index)
{
    if (index == maxN)
    {
        for (int i = 0; i < index; ++i)
        {
            if (judge[i])
            {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
    }
    else
    {
        judge[index] = false;
        printSubset(arr, judge, index+1);
        judge[index] = true;
        printSubset(arr, judge, index+1);
    }
}

int main()
{
    int arr[maxN] = {1, 4, 5};
    bool judge[maxN];
    printSubset(arr, judge, 0);
    return 0;
}