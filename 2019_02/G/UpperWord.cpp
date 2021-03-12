#include <iostream>
#include <string>

int main()
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        line[0] = toupper(line[0]);
        for(int i = 0; i != line.length(); ++i)
            if(line[i] == ' ' && i+1 != line.length())
                line[i+1] = toupper(line[i+1]);
        std::cout << line << std::endl;
    }
    return 0;
}