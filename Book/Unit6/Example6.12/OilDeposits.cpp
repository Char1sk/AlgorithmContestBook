#include <iostream>
#include <vector>
#include <utility>

const std::vector<std::pair<int, int>> directions {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
};

void markBlock(std::vector<std::vector<char>> &v, int x, int y, int r, int c, int mark)
{
    if (0 <= x && x < r && 0 <= y && y < c && v[x][y] == '@')
    {
        v[x][y] = mark;
        for (auto &p : directions)
        {
            markBlock(v, x+p.first, y+p.second, r, c, mark);
        }
    }
}

int main()
{
    int row, col;
    while (std::cin >> row >> col && row && col)
    {
        getchar();
        std::vector<std::vector<char>> grids(row, std::vector<char>(col));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                grids[i][j] = getchar();
            }
            getchar();
        }
        
        int cnt = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grids[i][j] == '@')
                {
                    markBlock(grids, i, j, row, col, ++cnt);
                }
            }
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}