#include <iostream>

const int maxN = 3;

// [0, maxN-1] subsets
void printSubset(int arr[maxN], int out[maxN], int index)
{
    for (int i = 0; i < index; ++i)
    {
        printf("%d ", out[i]);
    }
    printf("\n");
    
    // can be optimized by Mapping
    // to find the index of last value
    int beg = 0;
    if (index > 0)
    {
        int val = out[index-1];
        for (int i = 0; i < maxN; ++i)
        {
            if (arr[i] == val)
            {
                beg = i+1;
                break;
            }
        }
    }
    
    for (int i = beg; i < maxN; ++i)
    {
        out[index] = arr[i];
        printSubset(arr, out, index+1);
    }
}

int main()
{
    int arr[maxN] = {1, 4, 5};
    int out[maxN];
    printSubset(arr, out, 0);
    return 0;
}