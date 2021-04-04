#include <iostream>
#include <cstring>

const int maxN = 8;

void placeQueen(bool board[maxN][maxN], int row)
{
    static int cases = 0;
    if (row == maxN)
    {
        printf("Case %d: \n", ++cases);
        for (int i = 0; i < maxN; ++i)
        {
            for (int j = 0; j < maxN; ++j)
            {
                printf("%c", (board[i][j] ? 'x' : '.'));
            }
            printf("\n");
        }
        printf("\n");
    }
    else
    {
        for (int col = 0; col < maxN; ++col)
        {
            bool canPlace = true;
            for (int i = 0; i < row; ++i)
            {
                int delta = row - i;
                if ((0 <= col-delta && col-delta < maxN && board[i][col-delta]) || 
                    (0 <= col+delta && col+delta < maxN && board[i][col+delta]) || 
                     board[i][col])
                {
                    canPlace = false;
                    break;
                }
            }
            if (canPlace)
            {
                board[row][col] = true;
                placeQueen(board, row+1);
                board[row][col] = false;
            }
        }
    }
}

int main()
{
    freopen("./out.txt", "w", stdout);
    bool board[maxN][maxN];
    memset(board, 0, sizeof(board));
    placeQueen(board, 0);
    return 0;
}