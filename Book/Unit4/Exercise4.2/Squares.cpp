#include <iostream>

bool hlines[10][10];
bool vlines[10][10];

void init()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            hlines[i][j] = false;
            vlines[i][j] = false;
        }
    }
}

bool isSquare(int x, int y, int sz)
{
    for (int len = 0; len < sz; ++len)
    {
        if (! (hlines[x][y+len] && hlines[x+sz][y+len] && vlines[x+len][y] && vlines[x+len][y+sz]) )
        {
            // std::cout << "???" << x << ' ' << y << ' ' << sz << ' ' << len << std::endl;
            // std::cout << hlines[x][y+len] << hlines[x+sz][y+len] << vlines[x+len][y] << vlines[x+len][y+sz] << std::endl;
            return false;
        }
    }
    return true;
}

int main()
{
    int cases = 0;
    int n;
    int lineCount;
    while (std::cin >> n >> lineCount)
    {
        init();
        while (lineCount--)
        {
            char c;
            int x, y;
            std::cin >> c >> x >> y;
            switch (c)
            {
            case 'H':
                hlines[x][y] = true;
                break;
            case 'V':
                vlines[y][x] = true;
                break;
            default:
                break;
            }
        }
        
        if (cases)
        {
            std::cout << std::endl << "**********************************" << std::endl << std::endl;
        }
        printf("Problem #%d\n\n", ++cases);
        
        bool hasSquare = false;
        for (int sz = 1; sz <= n; ++sz)
        {
            int nowCount = 0;
            for (int i = 1; i <= n-sz+1; ++i)
            {
                for (int j = 1; j <= n-sz+1; ++j)
                {
                    nowCount += isSquare(i, j, sz);
                }
            }
            if (nowCount)
            {
                hasSquare = true;
                printf("%d square (s) of size %d\n", nowCount, sz);
            }
        }
        if (!hasSquare)
        {
            std::cout << "No completed squares can be found." << std::endl;
        }
    }
    return 0;
}