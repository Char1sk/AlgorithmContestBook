#include <iostream>
#include <cstring>

const int maxn = 10;

void printArrange(bool digits[maxn], int val[maxn], int idx)
{
    if (idx == maxn)
    {
        for (int i = 0; i < maxn; ++i)
        {
            std::cout << val[i] << ' ';
        }
        std::cout << std::endl;
    }
    else
    {
        for (int i = 0; i < maxn; ++i)
        {
            if (!digits[i])
            {
                digits[i] = true;
                val[idx] = i+1;
                printArrange(digits, val, idx+1);
                digits[i] = false;
            }
        }
    }
}

int main()
{
    bool digits[maxn];
    int val[maxn];
    memset(digits, 0, sizeof(digits));
    printArrange(digits, val, 0);
    return 0;
}