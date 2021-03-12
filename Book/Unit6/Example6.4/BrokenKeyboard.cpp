#include <iostream>
#include <string>
#include <deque>

int main()
{
    std::string line;
    while (std::getline(std::cin, line))
    {
        bool isEnd = true;
        std::deque<std::string> text;
        std::string buffer;
        for (auto &c : line)
        {
            if (c == '[' || c == ']')
            {
                if (!buffer.empty())
                {
                    if (isEnd)
                    {
                        text.push_back(buffer);
                    }
                    else
                    {
                        text.push_front(buffer);
                    }
                }
                buffer.clear();
                isEnd = (c == ']');
            }
            else
            {
                buffer.push_back(c);
            }
        }
        if (!buffer.empty())
        {
            if (isEnd)
            {
                text.push_back(buffer);
            }
            else
            {
                text.push_front(buffer);
            }
        }
        
        for (auto &s : text)
        {
            std::cout << s;
        }
        std::cout << std::endl;
    }
    return 0;
}