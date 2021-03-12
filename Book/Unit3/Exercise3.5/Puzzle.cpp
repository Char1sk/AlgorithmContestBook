#include <iostream>
#include <string>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases = 0;
    char puzzle[5][5];
    do
    {
        int blankRow, blankCol;
        bool isLegal = true;
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                puzzle[i][j] = getchar();
                if (puzzle[i][j] == ' ')
                {
                    blankRow = i;
                    blankCol = j;
                }
                if ( i == 0 && j == 0 && puzzle[0][0] == 'Z')
                {
                    goto EndLoop;
                }
            }
            getchar();
        }
        
        char tempc;
        while ( (tempc = getchar()) != '0' )
        {
            switch (tempc)
            {
            case 'A':
                if (blankRow != 0)
                {
                    puzzle[blankRow][blankCol] = puzzle[blankRow-1][blankCol];
                    puzzle[blankRow-1][blankCol] = ' ';
                    --blankRow;
                }
                else
                {
                    isLegal = false;
                }
                break;
            case 'B':
                if (blankRow != 4)
                {
                    puzzle[blankRow][blankCol] = puzzle[blankRow+1][blankCol];
                    puzzle[blankRow+1][blankCol] = ' ';
                    ++blankRow;
                }
                else
                {
                    isLegal = false;
                }
                break;
            case 'L':
                if (blankCol != 0)
                {
                    puzzle[blankRow][blankCol] = puzzle[blankRow][blankCol-1];
                    puzzle[blankRow][blankCol-1] = ' ';
                    --blankCol;
                }
                else
                {
                    isLegal = false;
                }
                break;
            case 'R':
                if (blankCol != 4)
                {
                    puzzle[blankRow][blankCol] = puzzle[blankRow][blankCol+1];
                    puzzle[blankRow][blankCol+1] = ' ';
                    ++blankCol;
                }
                else
                {
                    isLegal = false;
                }
                break;
            default:
                break;
            }
        }
        getchar();
        
        if (cases++)
        {
            std::cout << std::endl;
        }
        printf("Puzzle #%d:\n", cases);
        if (isLegal)
        {
            for (int i = 0; i < 5; ++i)
            {
                for (int j = 0; j < 5; ++j)
                {
                    if (j)
                    {
                        std::cout << ' ' ;
                    }
                    std::cout << puzzle[i][j] ;
                }
                std::cout << std::endl;
            }
        }
        else
        {
            std::cout << "This puzzle has no final configuration." << std::endl;
        }
    }
    while (true);
    EndLoop:
    
    return 0;
}