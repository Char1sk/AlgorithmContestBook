#include <iostream>


const int maxN = 100000+5;
int data[maxN] = {0};

int quickSort(int left, int right)
{
    // [left, right]
    if (left < right)
    {
        bool isLeft = true;
        int pIndex = left;
        int lIndex = left;
        int rIndex = right;
        while (lIndex <= rIndex)
        {
            int pivot = data[pIndex];
            if(isLeft)
            {
                if (pivot > data[rIndex])
                {
                    data[pIndex] = data[rIndex];
                    data[rIndex] = pivot;
                    pIndex = rIndex;
                    isLeft = false;
                }
                --rIndex;
            }
            else
            {
                if (pivot < data[lIndex])
                {
                    data[pIndex] = data[lIndex];
                    data[lIndex] = pivot;
                    pIndex = lIndex;
                    isLeft = true;
                }
                ++lIndex;
            }
        }
        quickSort(left, pIndex-1);
        quickSort(pIndex+1, right);
    }
}

int main()
{
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i)
    {
        std::cin >> data[i];
    }
    quickSort(0, count-1);
    for (int i = 0; i < count; ++i)
    {
        printf("%d%c", data[i], (i==count-1 ? '\n' : ' '));
    }
    return 0;
}