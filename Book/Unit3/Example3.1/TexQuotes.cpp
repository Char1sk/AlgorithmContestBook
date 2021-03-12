#include <iostream>
#include <string>

int main()
{
    bool isFirst = true;
    
    // std::string line;
    // while (std::getline(std::cin, line))
    // {
    //     for (auto c : line)
    //     {
    //         if (c == '\"')
    //         {
    //             std::cout << (isFirst ? "``" : "\'\'") ;
    //             isFirst = !isFirst;
    //         }
    //         else
    //         {
    //             std::cout << c;
    //         }
    //     }
    //     std::cout << std::endl;
    // }
    
    int tempChar;
    while ( (tempChar = getchar()) != EOF )
    {
        char c = tempChar;
        if (c == '\"')
        {
            std::cout << (isFirst ? "``" : "\'\'") ;
            isFirst = !isFirst;
        }
        else
        {
            std::cout << c;
        }
    }
    
    return 0;
}