#include <iostream>
#include <string>
#include <cmath>

char getChar()
{
    char ret = getchar();
    while (ret == '\n')
        ret = getchar();
    return ret;
}

int main()
{
    int digitBias[20];
    for (int d = 1, b = 0; d < 20; b += pow(2, d)-1, ++d)
    {
        digitBias[d] = b;
    }
    
    std::string header;
    while (std::getline(std::cin, header))
    {
        while (true)
        {
            int digit = 0;
            digit += 4*(getChar()-'0');
            digit += 2*(getChar()-'0');
            digit += getChar()-'0';
            if (digit == 0)
                break;
            while (true)
            {
                std::string code;
                for (int i = 0; i < digit; ++i)
                {
                    code += getChar();
                }
                if (code == std::string(digit, '1'))
                    break;
                std::cout << header[std::stoi(code, 0, 2)+digitBias[digit]];
            }
        }
        getchar();
        std::cout << std::endl;
        // std::string code;
        // do
        // {
        //     std::string line;
        //     std::cin >> line;
        //     code += line;
        // } while (code.length() < 3 || code.substr(code.length()-3, 3) != "000");
        // getchar();
        // while (code.substr(0, 3) != "000")
        // {
        //     int digit = std::stoi(code.substr(0, 3), nullptr, 2);
        //     code = code.substr(3);
        //     while (code.substr(0, digit) != std::string(digit, '1'))
        //     {
        //         int pos = std::stoi(code.substr(0, digit), nullptr, 2)+digitBias[digit];
        //         code = code.substr(digit);
        //         if (pos < header.length())
        //             std::cout << header[pos];
        //     }
        //     code = code.substr(digit);
        // }
        // std::cout << std::endl;  
    }
}