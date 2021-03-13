#include <iostream>
#include <vector>
#include <string>

bool isFlag(char c)
{
    return isprint(c) && c != '-' && c != '|' && c != ' ' && c != '#';
}

void preorder(std::vector<std::string> &input, int row, int left, int right)
{
    if (row < 0 || row >= input.size())
        return;
    for (int i = left; i <= right && i < input[row].size(); ++i)
    {
        if (isFlag(input[row][i]))
        {
            std::cout << input[row][i] << '(' ;
            if (row+1 < input.size() && input[row+1][i] == '|')
            {
                int l = i, r = i;
                while (l >= 0 && input[row+2][l] == '-')
                {
                    --l;
                }
                if (l < 0)
                {
                    l = 0;
                }
                while (r < input[row+2].size() && input[row+2][r] == '-')
                {
                    ++r;
                }
                if (r >= input[row+2].size())
                {
                    r = input[row+2].size()-1;
                }
                preorder(input, row+3, l, r);
            }
            std::cout << ')' ;
        }
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    getchar();
    while (cases--)
    {
        std::vector<std::string> input;
        std::string line;
        while (std::getline(std::cin, line) && line != "#")
        {
            input.push_back(line);
        }
        
        std::cout << '(' ;
        preorder(input, 0, 0, 205);
        std::cout << ')' << std::endl;
    }
    return 0;
}

// 2
//     A
//     |
// --------
// B  C   D
//    |   |
//  ----- -
//  E   F G
// #
// e
// |
// ----
// f g
// #