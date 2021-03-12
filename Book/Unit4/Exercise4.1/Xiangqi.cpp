#include <iostream>
#include <cmath>

char board[12][12];

int max(int a, int b)
{
    return (a > b) ? a : b ;
}

int min(int a, int b)
{
    return (a < b) ? a : b ;
}

void init()
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            board[i][j] = ' ';
        }
    }
}

bool isPieceCheck(char piece, int redX, int redY, int blackX, int blackY)
{
    if (redX == blackX && redY == blackY)
        return false;
    switch (piece)
    {
    case 'G':
    case 'R':
    case 'C':
        if (redX != blackX && redY != blackY)
            return false;
        {
        int interCount = 0;
        if (redX == blackX)
        {
            // std::cout << min(redY, blackY) << ' ' << max(redY, blackY) << std::endl;
            for (int j = min(redY, blackY); j <= max(redY, blackY); ++j)
            {
                if (j != blackY && board[redX][j] != ' ')
                {
                    ++interCount;
                }
            }
        }
        if (redY == blackY)
        {
            // std::cout << min(redX, blackX) << ' ' << max(redX, blackX) << std::endl;
            for (int i = min(redX, blackX); i <= max(redX, blackX); ++i)
            {
                // std::cout << i << ',' << redY << board[i][redY] << std::endl;
                if (i != blackX && board[i][redY] != ' ')
                {
                    ++interCount;
                }
            }
        }
        // std::cout << redX << ' ' << redY << ' ' << interCount << std::endl;
        return ( (piece == 'C') ? (interCount == 2) : (interCount == 1) );
        }
        break;
    case 'H':
        if (redX != 1 && board[redX-1][redY] == ' ')
        {
            if (blackX == redX-2 && (blackY == redY-1 || blackY == redY+1))
                return true;
        }
        if (redX != 10 && board[redX+1][redY] == ' ')
        {
            if (blackX == redX+2 && (blackY == redY-1 || blackY == redY+1))
                return true;
        }
        if (redY != 1 && board[redX][redY-1] == ' ')
        {
            if (blackY == redY-2 && (blackX == redX-1 || blackX == redX+1))
                return true;
        }
        if (redX != 9 && board[redX][redY+1] == ' ')
        {
            if (blackY == redY+2 && (blackX == redX-1 || blackX == redX+1))
                return true;
        }
        return false;
        break;
    default:
        return false;
        break;
    }
}

bool isCheckmate(int blackX, int blackY)
{
    bool iscm = false;
    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            iscm = isPieceCheck(board[i][j], i, j, blackX, blackY);
            if (iscm) goto fEnd;
        }
    }
    fEnd:
    return iscm;
}

int main()
{
    int redCount;
    int blackGeneralX;
    int blackGeneralY;
    while ((std::cin >> redCount >> blackGeneralX >> blackGeneralY) && redCount && blackGeneralX && blackGeneralY)
    {
        init();
        int redGeneralX;
        int redGeneralY;
        while (redCount--)
        {
            char piece;
            int x, y;
            std::cin >> piece >> x >> y;
            board[x][y] = piece;
            if (piece == 'G')
            {
                redGeneralX = x;
                redGeneralY = y;
            }
        }
        bool iscm = true;
        if (blackGeneralY == redGeneralY)
        {
            int interCount = 0;
            for (int i = blackGeneralX; i <= redGeneralX; ++i)
            {
                if (board[i][redGeneralY] != ' ')
                {
                    ++interCount;
                }
            }
            iscm = !(interCount == 1);
            if (!iscm) {goto mEnd;}
        }
        if (blackGeneralX != 1)
        {
            iscm = isCheckmate(blackGeneralX-1, blackGeneralY);
            if (!iscm) {/* std::cout << 'a' << std::endl;  */goto mEnd;}
        }
        if (blackGeneralX != 3)
        {
            iscm = isCheckmate(blackGeneralX+1, blackGeneralY);
            if (!iscm) {/* std::cout << 'b' << std::endl;  */goto mEnd;}
        }
        if (blackGeneralY != 4)
        {
            iscm = isCheckmate(blackGeneralX, blackGeneralY-1);
            if (!iscm) {/* std::cout << 'c' << std::endl;  */goto mEnd;}
        }
        if (blackGeneralY != 6)
        {
            iscm = isCheckmate(blackGeneralX, blackGeneralY+1);
            if (!iscm) {/* std::cout << 'd' << std::endl;  */goto mEnd;}
        }
        mEnd:
        std::cout << (iscm ? "YES" : "NO") << std::endl;
    }
    return 0;
}
// 2 1 5 H 3 5 C 4 5