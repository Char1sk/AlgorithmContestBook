#include <iostream>
#include <string>
#include <vector>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int row, col;
    while (std::cin >> row >> col && row && col)
    {
        std::vector<std::vector<std::string>> formCommand(row);
        std::vector<std::vector<int>> formValue(row);
        int solveCount = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                std::string line;
                std::cin >> line;
                // if (isalpha(line[0]))
                // {
                    formCommand[i].push_back(line);
                    formValue[i].push_back(114514);
                // }
                // else
                // {
                    // formCommand[i].push_back("");
                    // formValue[i].push_back(std::stoi(line));
                    // ++solveCount;
                // }
            }
        }
        bool hasChanged = true;
        while (hasChanged)
        {
            hasChanged = false;
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    const std::string &cmd = formCommand[i][j];
                    if (!cmd.empty())
                    {
                        int nowIndex = 0;
                        int nowValue = 0;
                        int totalValue = 0;
                        int sign = 1;
                        bool canCal = true;
                        // std::vector<std::vector<int>> unsolvedGrid(row, std::vector<int>(col, 0));
                        while (nowIndex < cmd.size())
                        {
                            if (isdigit(cmd[nowIndex]))
                            {
                                nowValue *= 10;
                                nowValue += cmd[nowIndex]-'0';
                                nowIndex += 1;
                            }
                            else
                            {
                                totalValue += (sign * nowValue);
                                nowValue = 0;
                                if (isalpha(cmd[nowIndex]))
                                {
                                    int r = cmd[nowIndex]-'A';
                                    int c = cmd[nowIndex+1]-'0';
                                    nowIndex += 2;
                                    if (formValue[r][c] != 114514)
                                    {
                                        totalValue += sign * formValue[r][c];
                                    }
                                    else
                                    {
                                        canCal = false;
                                        break;
                                        // unsolvedGrid[r][c] += sign;
                                    }
                                }
                                else if (cmd[nowIndex] == '+')
                                {
                                    sign = 1;
                                    nowIndex += 1;
                                }
                                else if (cmd[nowIndex] == '-')
                                {
                                    sign = -1;
                                    nowIndex += 1;
                                }
                            }
                        }
                        if (nowValue)
                        {
                            totalValue += (sign * nowValue);
                        }
                        
                        // bool canCal = true;
                        // for (int i = 0; i < row; ++i)
                        // {
                        //     for (int j = 0; j < col; ++j)
                        //     {
                        //         if (unsolvedGrid[i][j])
                        //         {
                        //             canCal = false;
                        //         }
                        //     }
                        // }
                        if (canCal)
                        {
                            ++solveCount;
                            hasChanged = true;
                            formValue[i][j] = totalValue;
                            formCommand[i][j].clear();
                        }
                    }
                }
            }
        }
        if (solveCount == row*col)
        {
            // std::cout << "yes!" << std::endl;
            
            printf(" ");
            for (int i = 0; i < col; ++i)
            {
                printf("%6d", i);
            }
            printf("\n");
            
            for (int i = 0; i < row; ++i)
            {
                printf("%c", i+'A');
                for (int j = 0; j < col; ++j)
                {
                    printf("%6d", formValue[i][j]);
                }
                printf("\n");
            }
            
            printf("\n");
        }
        else
        {
            // std::cout << "no!" << std::endl;
            for (int i = 0; i < row; ++i)
            {
                for (int j = 0; j < col; ++j)
                {
                    if (!formCommand[i][j].empty())
                    {
                        printf("%c%c: %s\n", i+'A', j+'0', formCommand[i][j].c_str());
                    }
                }
            }
            printf("\n");
        }
        
    }
    return 0;
}