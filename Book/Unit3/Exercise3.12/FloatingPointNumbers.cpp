#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

int main()
{
    std::map<std::pair<int, int>, double> table;
    
    
    double frac = 0;
    for (int i = 0; i <= 9; ++i)
    {
        frac += pow(0.5, i+1);
        for (int j = 1; j <= 30; ++j)
        {
            table.insert({ {i ,j}, log10(frac)+ log10(2) * (pow(2, j)-1) });
            // table[{i, j}] = frac * pow(2, pow(2, j)-1);
            // printf("%d, %d = %lf\n", i, j, log10(frac * pow(2, pow(2, j)-1)));
        }
    }
    
    std::string temp;
    while (std::getline(std::cin, temp, 'e') && temp != "0")
    {
        double frac = std::stod(temp);
        int expo = 0;
        std::cin >> expo;
        getchar();
        double val = log10(frac)+expo;
        // auto pr = table.begin();
        // printf("%.15lf ", log10(frac*pow(10, expo)));
        for (auto p : table)
        {
            if( std::abs(p.second - val) < 1e-5)
            {
                std::cout << p.first.first << ' ' << p.first.second << std::endl;
                break;
            }
        }
        // std::cout << p.first << ' ' << p.second << std::endl;
    }
    return 0;
}