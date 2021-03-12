#include <iostream>
#include <string>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string DNAs[50];
        int count, len;
        std::cin >> count >> len;
        for (int i = 0; i < count; ++i)
        {
            std::cin >> DNAs[i];
        }
        int distantce = 0;
        for (int j = 0; j < len; ++j)
        {
            int statistic[4] {0};
            for (int i = 0; i < count; ++i)
            {
                switch (DNAs[i][j])
                {
                case 'A':
                    ++statistic[0];
                    break;
                case 'C':
                    ++statistic[1];
                    break;
                case 'G':
                    ++statistic[2];
                    break;
                case 'T':
                    ++statistic[3];
                    break;
                default:
                    break;
                }
            }
            int maxCount = 0;
            int maxIndex = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (statistic[i] > maxCount)
                {
                    maxCount = statistic[i];
                    maxIndex = i;
                }
            }
            distantce += count - maxCount;
            switch (maxIndex)
            {
            case 0:
                std::cout << 'A';
                break;
            case 1:
                std::cout << 'C';
                break;
            case 2:
                std::cout << 'G';
                break;
            case 3:
                std::cout << 'T';
                break;
            default:
                break;
            }
        }
        std::cout << std::endl;
        std::cout << distantce << std::endl;
    }
    
    return 0;
}