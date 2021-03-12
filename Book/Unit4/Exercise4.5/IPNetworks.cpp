#include <iostream>
#include <vector>
#include <string>

std::string toBinary(const std::string &s)
{
    std::string ret;
    int n = std::stoi(s);
    for (int i = 0; i < 8; ++i)
    {
        // std::cout << n << std::endl;////
        ret += (n >= 128 ? '1' : '0');
        n <<= 1;
        n %= 256;
    }
    // std::cout << ret << ' ';////
    return ret;
}

std::string toIP(const std::string &s)
{
    std::string ret;
    for (int i = 0; i < 4; ++i)
    {
        int num = std::stoi(s.substr(8*i, 8), 0, 2);
        // for (int j = 0; j < 8; ++j)
        // {
        //     num += s[8*i+j] - '0';
        //     num <<= 1;
        // }
        ret += std::to_string(num);
        if (i != 3)
        {
            ret += '.';
        }
    }
    return ret;
}

int main()
{
    int len;
    while (std::cin >> len)
    {
        getchar();
        std::vector<std::string> ipAddresses;
        for (int c = 0; c < len; ++c)
        {
            std::string toPush;
            std::string temp;
            int byte;
            
            std::getline(std::cin, temp, '.');
            toPush += toBinary(temp);
            std::getline(std::cin, temp, '.');
            toPush += toBinary(temp);
            std::getline(std::cin, temp, '.');
            toPush += toBinary(temp);
            std::getline(std::cin, temp);
            toPush += toBinary(temp);
            
            ipAddresses.push_back(toPush);
            // std::cout << toPush << std::endl;////
        }
        int index = 0;
        for (int d = 0; d < 32; ++d)
        {
            for (int l = 0; l < len-1; ++l)
            {
                if (ipAddresses[l][d] != ipAddresses[l+1][d])
                {
                    goto End;
                }
            }
            ++index;
        }
        End:
        std::string address(ipAddresses[0], 0, index);
        address += std::string(32-index, '0');
        std::string mask(index, '1');
        mask += std::string(32-index, '0');
        std::cout << toIP(address) << std::endl;
        std::cout << toIP(mask) << std::endl;
        // std::cout << address << std::endl << mask << std::endl;
    }
    return 0;
}