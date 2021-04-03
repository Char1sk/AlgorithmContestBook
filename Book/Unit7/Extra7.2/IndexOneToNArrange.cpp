#include <iostream>
#include <cstring>

const int maxN = 6;

void printArrange(bool used[maxN], bool first[maxN], int sequence[maxN], const int data[maxN], int index)
{
    if (index == maxN)
    {
        for (int i = 0; i < maxN; ++i)
        {
            std::cout << sequence[i] << ' ';
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = 0; i < maxN; ++i)
        {
            if (!used[i] && (first[index] || sequence[index] != data[i]))
            {
                used[i] = true;
                first[index] = false;
                sequence[index] = data[i];
                printArrange(used, first, sequence, data, index+1);
                used[i] = false;
                if (index != maxN-1)
                {
                    first[index+1] = true;
                }
            }
        }
    }
}

int main()
{
    int data[maxN] = {1, 1, 1, 4, 4, 5};
    // int data[maxN] = {1, 1, 1, 2};
    int sequence[maxN];
    bool used[maxN];
    memset(used, 0, sizeof(used));
    bool first[maxN];
    memset(first, 1, sizeof(first));
    printArrange(used, first, sequence, data, 0);
    std::cout << "end" << std::endl;
    return 0;
}