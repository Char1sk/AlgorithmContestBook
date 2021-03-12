#include <iostream>

int main()
{
    // freopen("./out.txt", "w", stdout);
    
    int triangle[30][30] = {0};
    for(int i = 0; i != 30; ++i)
        for(int j = 0; j != i+1; ++j)
            if(j == 0)
                triangle[i][j] = 1;
            else
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
    
    int layer;
    while(std::cin >> layer)
    {
        for(int i = 0; i != layer; ++i)
        {
            bool is_first_one = true;
            for(int j = 0; j != i+1; ++j)
            {
                if(is_first_one)
                    is_first_one = false;
                else
                    std::cout << ' ';
                std::cout << triangle[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}