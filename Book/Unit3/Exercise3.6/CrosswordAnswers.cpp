#include <iostream>

class Grid
{
public:
    int number;
    bool isRowFirst;
    bool isColFirst;
    char content;
    
    Grid(int n = 0, bool rf = false, bool cf = false, char ch = '*') :
         number(n), isRowFirst(rf), isColFirst(cf), content(ch) {}
    bool isBlack()
    {
        return content == '*';
    }
};

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases = 0;
    int rows, cols;
    while (std::cin >> rows >> cols)
    {
        Grid grids[10][10];
        getchar();
        int headNumber = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                grids[i][j].content = getchar();
                if ( (!grids[i][j].isBlack()) && (j == 0 || grids[i][j-1].isBlack()) )
                {
                    grids[i][j].isRowFirst = true;
                }
                if ( (!grids[i][j].isBlack()) && (i == 0 || grids[i-1][j].isBlack()) )
                {
                    grids[i][j].isColFirst = true;
                }
                if (grids[i][j].isRowFirst || grids[i][j].isColFirst)
                {
                    grids[i][j].number = ++headNumber;
                }
            }
            getchar();
        }
        
        if (cases)
        {
            std::cout << std::endl;
        }
        printf("puzzle #%d:\n", ++cases);
        
        std::cout << "Across" << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grids[i][j].isRowFirst)
                {
                    printf("%3.d.", grids[i][j].number);
                    for (int k = j; k < cols && !grids[i][k].isBlack(); ++k)
                    {
                        std::cout << grids[i][k].content ;
                    }
                    std::cout << std::endl;
                }
            }
        }
        
        std::cout << "Down" << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grids[i][j].isColFirst)
                {
                    printf("%3.d.", grids[i][j].number);
                    for (int k = i; k < rows && !grids[k][j].isBlack(); ++k)
                    {
                        std::cout << grids[k][j].content ;
                    }
                    std::cout << std::endl;
                }
            }
        }
        
    }
    return 0;
}