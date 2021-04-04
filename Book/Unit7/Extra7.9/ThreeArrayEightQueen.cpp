#include <iostream>
#include <cstring>

const int maxN = 8;

void placeQueen(bool cantPlace[3][2*maxN], int colOut[maxN], int row)
{
    static int cases = 0;
    
    if (row == maxN)
    {
        printf("Case %d:\n", ++cases);
        for (int i = 0; i < maxN; ++i)
        {
            for (int j = 0; j < maxN; ++j)
            {
                printf("%c ", (colOut[i]==j ? 'x' : '.'));
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for (int c = 0; c < maxN; ++c)
        {
            if (!cantPlace[0][c] && !cantPlace[1][row-c+maxN] && !cantPlace[2][row+c])
            {
                cantPlace[0][c] = true;
                cantPlace[1][row-c+maxN] = true;
                cantPlace[2][row+c] = true;
                colOut[row] = c;
                placeQueen(cantPlace, colOut, row+1);
                cantPlace[0][c] = false;
                cantPlace[1][row-c+maxN] = false;
                cantPlace[2][row+c] = false;
            }
        }
    }
    
}

int main()
{
    freopen("./out.txt", "w", stdout);
    int colOut[maxN];
    bool cantPlace[3][2*maxN];
    memset(cantPlace, 0, sizeof(cantPlace));
    placeQueen(cantPlace, colOut, 0);
    return 0;
}