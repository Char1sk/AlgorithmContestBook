#include <iostream>
#include <string>

int main()
{
    bool isFirst = true;
    int quotient;
    while (std::cin >> quotient && quotient)
    {
        if (!isFirst)
        {
            std::cout << std::endl;
        }
        isFirst = false;
        
        bool haveSolution = false;
        for (int mother = 01234; quotient * mother <= 98765; ++mother)
        {
            int son = mother * quotient;
            std::string momString(std::to_string(mother));
            std::string sonString(std::to_string(son));
            int statistics[10] = {10, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            for (char c : momString)
            {
                int v = c-'0';
                --statistics[0];
                ++statistics[v];
            }
            for (char c : sonString)
            {
                int v = c-'0';
                --statistics[0];
                ++statistics[v];
            }
            bool oneSolution = true;
            for (int i = 0; i < 10; ++i)
            {
                if (statistics[i] != 1)
                {
                    oneSolution = false;
                    break;
                }
            }
            if (oneSolution)
            {
                haveSolution = true;
                printf("%05d / %05d = %d\n", son, mother, quotient);
            }
        }
        if (!haveSolution)
        {
            printf("There are no solutions for %d.\n", quotient);
        }
    }
    return 0;
}