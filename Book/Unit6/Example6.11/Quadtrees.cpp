#include <iostream>
#include <vector>
#include <cstring>

void paint(bool pixels[32][32], int &cnt, int x, int y, int len)
{
    char c = getchar();
    if (c == 'p')
    {
        int delta = len / 2;
        paint(pixels, cnt, x,       y+delta, delta);
        paint(pixels, cnt, x,       y,       delta);
        paint(pixels, cnt, x+delta, y,       delta);
        paint(pixels, cnt, x+delta, y+delta, delta);
    }
    else if (c == 'f')
    {
        for (int i = x; i < x+len; ++i)
        {
            for (int j = y; j < y+len; ++j)
            {
                if (!pixels[i][j])
                {
                    pixels[i][j] = true;
                    ++cnt;
                }
            }
        }
    }
}

void paint_simulate()
{
    int cases;
    std::cin >> cases;
    getchar();
    while (cases--)
    {
        bool pixels[32][32];
        memset(pixels, 0, sizeof(pixels));
        int cnt = 0;
        paint(pixels, cnt, 0, 0, 32);
        getchar();
        paint(pixels, cnt, 0, 0, 32);
        getchar();
        printf("There are %d black pixels.\n", cnt);
    }
}

void tree_simulate()
{
    
}

int main()
{
    paint_simulate();
    return 0;
}