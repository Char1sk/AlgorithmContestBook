#include <iostream>
#include <string>

double getMass(char c)
{
    switch (c)
    {
    case 'C':
        return 12.01;
    case 'H':
        return 1.008;
    case 'O':
        return 16.00;
    case 'N':
        return 14.01;
    default:
        return 0.0;
    }
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        std::string molar;
        std::cin >> molar;
        
        double sum = 0;
        int idx;
        int count;
        char element = molar[0];
        std::string temp(molar, 1, molar.size());
        while ( (idx = temp.find_first_of("CHON")) != std::string::npos )
        {
            if (idx == 0)
                count = 1;
            else
                count = std::stoi(temp.substr(0, idx));
            sum += count * getMass(element);
            element = temp[idx];
            temp = temp.substr(idx+1, temp.length()-idx);
        }
        try
        {
            count = std::stoi(temp.substr(0, idx));
        }
        catch(const std::exception& e)
        {
            count = 1;
        }
        sum += count * getMass(element);
        printf("%.3lf\n", sum);
    }
    return 0;
}