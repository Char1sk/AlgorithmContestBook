#include <iostream>
#include <cstdio>

const int maxN = 10;
int cases = 0;
int N = 0;
int board[maxN];

void printBoard()
{
    if (cases++ != 0)
    {
        printf("\n");
    }
    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            if (c == board[r])
            {
                printf("Q");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

bool canPlace(int row, int col)
{
    for (int r = 0; r < row; ++r)
    {
        int c = board[r];
        if ( (c == col) || (row-r == col-c) || (row-r == c-col) )
        {
            return false;
        }
    }
    return true;
}

void placeQueen(int row)
{
    if (row == N)
    {
        printBoard();
        return;
    }
    for (int col = 0; col < N; ++col)
    {
        if (canPlace(row, col))
        {
            board[row] = col;
            placeQueen(row+1);
        }
    }
}

int main()
{
    std::cin >> N;
    placeQueen(0);
    // std::cout << cases << std::endl;
    return 0;
}