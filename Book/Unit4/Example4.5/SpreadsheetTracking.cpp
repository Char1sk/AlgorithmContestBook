#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Grid
{
    int row;
    int col;
    Grid(int r = -1, int c = -1) : row(r), col(c) {}
};

Grid grids[60][60];

void init()
{
    for (int i = 0; i < 60; ++i)
    {
        for (int j = 0; j < 60; ++j)
        {
            grids[i][j].row = i;
            grids[i][j].col = j;
        }
        // rowFunc[i] = i;
        // colFunc[i] = i;
    }
}

int main()
{
    int cases = 0;
    int oldRows, oldCols;
    while ((std::cin >> oldRows >> oldCols) && oldRows && oldCols)
    {
        init();
        int nowRows = oldRows;
        int nowCols = oldCols;
        int commandCount;
        std::cin >> commandCount;
        while (commandCount--)
        {
            std::string command;
            std::cin >> command;
            if (command == "DR")
            {
                std::vector<int> toDR;
                int opCount;
                std::cin >> opCount;
                while (opCount--)
                {
                    int nowRow;
                    std::cin >> nowRow;
                    toDR.push_back(nowRow);
                }
                std::sort(toDR.rbegin(), toDR.rend());
                for (int r : toDR)
                {
                    for (int i = r; i <= nowRows-1; ++i)
                    {
                        for (int j = 1; j <= nowCols; ++j)
                        {
                            grids[i][j] = grids[i+1][j];
                        }
                    }
                    --nowRows;
                }
            }
            if (command == "DC")
            {
                std::vector<int> toDC;
                int opCount;
                std::cin >> opCount;
                while (opCount--)
                {
                    int nowCol;
                    std::cin >> nowCol;
                    toDC.push_back(nowCol);
                }
                std::sort(toDC.rbegin(), toDC.rend());
                for (int c : toDC)
                {
                    for (int j = c; j <= nowCols-1; ++j)
                    {
                        for (int i = 1; i <= nowRows; ++i)
                        {
                            grids[i][j] = grids[i][j+1];
                        }
                        // colFunc[i] = colFunc[i+1];
                    }
                    --nowCols;
                }
            }
            if (command == "IR")
            {
                std::vector<int> toIR;
                int opCount;
                std::cin >> opCount;
                while (opCount--)
                {
                    int nowRow;
                    std::cin >> nowRow;
                    toIR.push_back(nowRow);
                }
                std::sort(toIR.rbegin(), toIR.rend());
                for (int r : toIR)
                {
                    for (int i = nowRows+1; i >= r+1; --i)
                    {
                        for (int j = 1; j <= nowCols; ++j)
                        {
                            grids[i][j] = grids[i-1][j];
                        }
                        // rowFunc[i] = rowFunc[i-1];
                    }
                    for (int j = 1; j <= nowCols; ++j)
                    {
                        grids[r][j].row = 0;
                        grids[r][j].col = 0;
                    }
                    ++nowRows;
                }
            }
            if (command == "IC")
            {
                std::vector<int> toIC;
                int opCount;
                std::cin >> opCount;
                while (opCount--)
                {
                    int nowCol;
                    std::cin >> nowCol;
                    toIC.push_back(nowCol);
                }
                std::sort(toIC.rbegin(), toIC.rend());
                for (int c : toIC)
                {
                    for (int j = nowCols+1; j >= c+1; --j)
                    {
                        // colFunc[j] = colFunc[j-1];
                        for (int i = 1; i <= nowRows; ++i)
                        {
                            grids[i][j] = grids[i][j-1];
                        }
                    }
                    for (int i = 1; i <= nowRows; ++i)
                    {
                        grids[i][c].row = 0;
                        grids[i][c].col = 0;
                    }
                    // colFunc[c] = 0;
                    ++nowCols;
                }
            }
            if (command == "EX")
            {
                int r1, c1, r2, c2;
                std::cin >> r1 >> c1 >> r2 >> c2;
                std::swap(grids[r1][c1].row, grids[r2][c2].row);
                std::swap(grids[r1][c1].col, grids[r2][c2].col);
            }
        }
        
        if (cases)
        {
            std::cout << std::endl;
        }
        printf("Spreadsheet #%d\n", ++cases);
        int queryCount;
        std::cin >> queryCount;
        while (queryCount--)
        {
            int queryRow, queryCol;
            std::cin >> queryRow >> queryCol;
            int realRow = -1, realCol = -1;
            for (int i = 1; i <= nowRows; ++i)
            {
                for (int j = 1; j <= nowCols; ++j)
                {
                    if (grids[i][j].row == queryRow && grids[i][j].col == queryCol)
                    {
                        realRow = i;
                        realCol = j;
                    }
                    // std::cout << grids[i][j].row << grids[i][j].col << ' ';
                }
                // std::cout << std::endl;
            }
            
            printf("Cell data in (%d,%d) ", queryRow, queryCol);
            if (realRow == -1 || realCol == -1)
            {
                printf("GONE\n");
            }
            else
            {
                printf("moved to (%d,%d)\n", realRow, realCol);
            }
        }
    }
    return 0;
}
// 1 2 3 4 5 6 7 8 9
// 1 2 3 5 7 8 9
// 2 3 5 7 8

// 1 2 3 4 5
// 1 0 2 3 0 4 5
// 0 1 0 2 3 0 0 4 5

// 21 22 23 24 25 28 28 28 29
// 31 32 33 34 35 38 38 38 39
// 41 42 43 44 45 48 48 48 49
// 61 62 63 64 65 68 68 68 69
// 71 72 73 74 75 78 78 78 79
// 71 72 73 74 75 78 78 78 79 //
// 71 72 73 74 75 78 78 78 79 //
//                   // // //
// 5 6