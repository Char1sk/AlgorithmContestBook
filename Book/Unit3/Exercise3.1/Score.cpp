#include <iostream>
#include <string>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string line;
        std::cin >> line;
        int OCount = 0;
        int score = 0;
        for (int i = 0; i != line.length(); ++i)
        {
            if (line[i] == 'O')
            {
                score += ++OCount;
            }
            else
            {
                OCount = 0;
            }
        }
        std::cout << score << std::endl;
    }
    return 0;
}