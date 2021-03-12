#include <iostream>
#include <string>

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string origin;
        std::cin >> origin;
        int start = 0;
        int len = origin.length();
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (origin[(i+j)%len] < origin[(start+j)%len])
                {
                    start = i;
                    break;
                }
                if (origin[(i+j)%len] > origin[(start+j)%len])
                {
                    break;
                }
            }
        }
        for (int i = 0; i < len; ++i)
        {
            std::cout << origin[(i+start)%len] ;
        }
        std::cout << std::endl;
    }
    return 0;
}