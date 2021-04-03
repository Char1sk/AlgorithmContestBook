#include <iostream>

const int maxN = 5;

// [0, maxN-1] subsets
void printSubset(int arr[maxN], int index)
{
    for (int i = 0; i < index; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int beg = index ? (arr[index-1]+1) : 0 ;
    for (int i = beg; i < maxN; ++i)
    {
        arr[index] = i;
        printSubset(arr, index+1);
    }
}

int main()
{
    int arr[maxN];
    printSubset(arr, 0);
    return 0;
}