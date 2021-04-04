#include <iostream>

const int maxN = 8;

void placeQueen(int colInRow[maxN], int row)
{
    static int cases = 0;
    
    if (row == maxN)
    {
        printf("Case %d:\n", ++cases);
        for (int i = 0; i < maxN; ++i)
        {
            for (int j = 0; j < maxN; ++j)
            {
                printf("%c ", (colInRow[i]==j ? 'x' : '.'));
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for (int c = 0; c < maxN; ++c)
        {
            bool canPlace = true;
            for (int r = 0; r < row; ++r)
            {
                if (colInRow[r] == c || colInRow[r]-r == c-row || colInRow[r]+r == c+row)
                {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace)
            {
                colInRow[row] = c;
                placeQueen(colInRow, row+1);
            }
        }
    }
}

int main()
{
    freopen("./out.txt", "w", stdout);
    int colInRow[maxN];
    placeQueen(colInRow, 0);
    return 0;
}