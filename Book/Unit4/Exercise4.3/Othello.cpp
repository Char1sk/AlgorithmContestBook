#include <iostream>
#include <vector>

char board[10][10];

const int directions[8][2]{
    {-1, -1},
    {-1,  0},
    {-1,  1},
    { 0, -1},
    { 0,  1},
    { 1, -1},
    { 1,  0},
    { 1,  1}
};

bool legalMove(bool isWhite, int x, int y, bool canMove = false)
{
    bool legal = false;
    for (int d = 0; d < 8; ++d)
    {
        bool hasTrans = false;
        std::vector<std::vector<int>> trans;
        for (int i = x+directions[d][0], j = y+directions[d][1]; 
                1 <= i && i <= 8 && 1 <= j && j <= 8; i += directions[d][0], j += directions[d][1])
        {
            if ( board[i][j] == (isWhite ? 'B' : 'W') )
            {
                hasTrans = true;
                trans.push_back({i, j});
            }
            else if ( (board[i][j] == (isWhite ? 'W' : 'B')) && hasTrans )
            {
                legal = true;
                if (canMove)
                {
                    board[x][y] = (isWhite ? 'W' : 'B');
                    for (auto p : trans)
                    {
                        board[p[0]][p[1]] = (isWhite ? 'W' : 'B');
                    }
                }
                break; 
            }
            else
            {
                break;
            }
            
        }
    }
    return legal;
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    std::cin >> cases;
    getchar();
    while (cases--)
    {
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                board[i][j] = getchar();
            }
            getchar();
        }
        
        bool isWhite = (getchar() == 'W');
        getchar();
        
        char command;
        while ( (command = getchar()) != 'Q' )
        {
            switch (command)
            {
            case 'L':
                {
                bool hasLegal = false;
                for (int i = 1; i <= 8; ++i)
                {
                    for (int j = 1; j <= 8; ++j)
                    {
                        if (board[i][j] == '-' && legalMove(isWhite, i, j))
                        {
                            if (hasLegal)
                            {
                                std::cout << ' ' ;
                            }
                            printf("(%d,%d)", i, j);
                            hasLegal = true;
                        }
                    }
                }
                if (!hasLegal)
                {
                    std::cout << "No legal move." ;
                }
                std::cout << std::endl;
                break;
                }
            case 'M':
                {
                int x = getchar() - '0';
                int y = getchar() - '0';
                if (!legalMove(isWhite, x, y, true))
                {
                    isWhite = !isWhite;
                    legalMove(isWhite, x, y, true);
                }
                isWhite = !isWhite;
                int whiteCount = 0;
                int blackCount = 0;
                for (int i = 1; i <= 8; ++i)
                {
                    for (int j = 1; j <= 8; ++j)
                    {
                        if (board[i][j] == 'W')
                        {
                            ++whiteCount;
                        }
                        if (board[i][j] == 'B')
                        {
                            ++blackCount;
                        }
                    }
                }
                printf("Black - %2d White - %2d\n", blackCount, whiteCount);
                
                break;
                }
            default:
                break;
            }
            getchar();
        }
        getchar();
        
        for (int i = 1; i <= 8; ++i)
        {
            for (int j = 1; j <= 8; ++j)
            {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
        if (cases)
        {
            std::cout << std::endl;
        }
    }
    return 0;
}