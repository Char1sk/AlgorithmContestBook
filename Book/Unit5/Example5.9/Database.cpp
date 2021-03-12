#include <iostream>
#include <vector>
#include <map>
#include <string>

std::map<std::string, int> strToID;
int id = 0;

int getID(const std::string &s)
{
    if (strToID[s] == 0)
    {
        strToID[s] = ++id;
    }
    return strToID[s];
}

void solve1()
{
    int rows, cols;
    while (std::cin >> rows >> cols)
    {
        getchar();
        std::map<std::string, std::vector<int>> dataToRowNum[12];
        std::vector<std::vector<std::string>> data;
        for (int i = 0; i < rows; ++i)
        {
            std::vector<std::string> dataRow;
            for (int j = 0; j < cols; ++j)
            {
                std::string stemp;
                std::getline(std::cin, stemp, (j == cols-1 ? '\n' : ','));
                dataRow.push_back(stemp);
                dataToRowNum[j][stemp].push_back(i);
            }
            data.push_back(dataRow);
        }
        
        bool isPNF = true;
        for (int c1 = 0; c1 < cols; ++c1)
        {
            for (auto &p : dataToRowNum[c1])
            {
                for (int i1 = 0; i1 < p.second.size(); ++i1)
                {
                    int r1 = p.second[i1];
                    for (int i2 = i1+1; i2 < p.second.size(); ++i2)
                    {
                        int r2 = p.second[i2];
                        for (int c2 = c1+1; c2 < cols; ++c2)
                        {
                            if (data[r1][c2] == data[r2][c2])
                            {
                                isPNF = false;
                                std::cout << "NO" << std::endl;
                                std::cout << r1+1 << ' ' << r2+1 << std::endl;
                                std::cout << c1+1 << ' ' << c2+1 << std::endl;
                                goto End;
                            }
                        }
                    }
                }
            }
        }
        
        End:
        if (isPNF)
        {
            std::cout << "YES" << std::endl;
        }
    }
}

void solve2()
{
    int rows, cols;
    while (std::cin >> rows >> cols)
    {
        getchar();
        std::vector<std::vector<int>> data;
        for (int i = 0; i < rows; ++i)
        {
            std::vector<int> dataRow;
            for (int j = 0; j < cols; ++j)
            {
                std::string stemp;
                std::getline(std::cin, stemp, (j == cols-1 ? '\n' : ','));
                dataRow.push_back(getID(stemp));
            }
            data.push_back(dataRow);
        }
        
        bool isPNF = true;
        for (int c1 = 0; c1 < cols; ++c1)
        {
            for (int c2 = c1+1; c2 < cols; ++c2)
            {
                std::map<std::pair<int, int>, int> pairToRowNum;
                for (int r = 0; r < rows; ++r)
                {
                    if (pairToRowNum.find({data[r][c1], data[r][c2]}) == pairToRowNum.end())
                    {
                        pairToRowNum.insert({{data[r][c1], data[r][c2]}, r});
                    }
                    else
                    {
                        isPNF = false;
                        auto it = pairToRowNum.find({data[r][c1], data[r][c2]});
                        std::cout << "NO" << std::endl;
                        std::cout << it->second+1 << ' ' << r+1 << std::endl;
                        std::cout << c1+1 << ' ' << c2+1 << std::endl;
                        goto End;
                    }
                    
                }
            }
        }
        
        End:
        if (isPNF)
        {
            std::cout << "YES" << std::endl;
        }
    }
}

int main()
{
    solve1();
    return 0;
}