#include <iostream>
#include <string>

int main()
{
    int cases = 0;
    int depth;
    while (std::cin >> depth && depth)
    {
        int sequence[10] = {0};
        for (int i = 0; i < depth; ++i)
        {
            std::string node;
            std::cin >> node;
            int n = node.back() - '1';
            sequence[i] = n;
        }
        std::string answers;
        std::cin >> answers;
        
        printf("S-Tree #%d:\n", ++cases);
        int queryCnt;
        std::cin >> queryCnt;
        while (queryCnt--)
        {
            std::string line;
            std::cin >> line;
            
            int index = 0;
            for (int i = 0; i < depth; ++i)
            {
                index <<= 1;
                index += line[sequence[i]]-'0';
            }
            std::cout << answers[index];
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}