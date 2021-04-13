#include <iostream>
#include <vector>

int main()
{
    int matCnt;
    std::cin >> matCnt;
    std::vector<int> dims(matCnt+1);
    for (int d = 0; d < matCnt+1; ++d)
    {
        std::cin >> dims[d];
    }
    
    std::vector<std::vector<int>> computes(matCnt+1, std::vector<int>(matCnt+1));
    for (int delta = 0; delta < matCnt; ++delta)
    {
        for (int row = 1; row <= matCnt-delta; ++row)
        {
            int col = row + delta;
            if (delta == 0)
            {
                computes[row][col] = 0;
            }
            else
            {
                int minTimes = INT32_MAX;
                for (int k = row; k < col; ++k)
                {
                    int nowTimes = computes[row][k] + computes[k+1][col] + dims[row-1]*dims[k]*dims[col];
                    if (nowTimes < minTimes)
                    {
                        minTimes = nowTimes;
                    }
                }
                computes[row][col] = minTimes;
            }
        }
    }
    std::cout << computes[1][matCnt] << std::endl;
    
    return 0;
}