#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>

const char holesToCharacter[] = "WAKJSD";

const std::pair<int, int> directions[] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

const std::map<char, std::string> hexToBin = {
    {'0',"0000"}, {'1',"0001"}, {'2',"0010"}, {'3',"0011"},
    {'4',"0100"}, {'5',"0101"}, {'6',"0110"}, {'7',"0111"},
    {'8',"1000"}, {'9',"1001"}, {'a',"1010"}, {'b',"1011"},
    {'c',"1100"}, {'d',"1101"}, {'e',"1110"}, {'f',"1111"}
};

void flood(std::vector<std::string> &g, int x, int y, int r, int c, char from, char to)
{
    if (0 <= x && x < r && 0 <= y && y < c && g[x][y] == from)
    {
        g[x][y] = to;
        for (auto &p : directions)
        {
            flood(g, x+p.first, y+p.second, r, c, from, to);
        }
    }
}

void flood(std::vector<std::string> &g, int x, int y, int r, int c, char from, char to, int &cnt)
{
    if (0 <= x && x < r && 0 <= y && y < c && g[x][y] == from)
    {
        g[x][y] = to;
        for (auto &p : directions)
        {
            int xx = x + p.first;
            int yy = y + p.second;
            if (0 <= xx && xx < r && 0 <= yy && yy < c && g[xx][yy] == '0')
            {
                ++cnt;
                flood(g, xx, yy, r, c, '0', '4');
            }
            flood(g, x+p.first, y+p.second, r, c, from, to, cnt);
        }
    }
}

int main()
{
    int cases = 0;
    int row, col;
    while (std::cin >> row >> col && row && col)
    {
        // read as '0' and '1'
        getchar();
        std::vector<std::string> graph(row);
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                char c = getchar();
                graph[i] += hexToBin.at(c);
            }
            getchar();
        }
        // flood background with '2'
        col *= 4;
        for (int i = 0; i < row; ++i)
        {
            if (i == 0 || i == row-1)
            {
                for (int j = 0; j < col; ++j)
                {
                    flood(graph, i, j, row, col, '0', '2');
                }
            }
            else
            {
                flood(graph, i, 0,     row, col, '0', '2');
                flood(graph, i, col-1, row, col, '0', '2');
            }
        }
        // // test out
        // for (int i = 0; i < row; ++i)
        // {
        //     std::cout << graph[i] << std::endl;
        // }
        
        // flood lines with '3' and holes with '4'
        // and will find the character
        std::string output;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (graph[i][j] == '1')
                {
                    int holeCount = 0;
                    flood(graph, i, j, row, col, '1', '3', holeCount);
                    output.push_back(holesToCharacter[holeCount]);
                }
            }
        }
        // for (int i = 0; i < row; ++i)
        // {
        //     std::cout << graph[i] << std::endl;
        // }////
        std::sort(output.begin(), output.end());
        printf("Case %d: %s\n", ++cases, output.c_str());
    }
    return 0;
}