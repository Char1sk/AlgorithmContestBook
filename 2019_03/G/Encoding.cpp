#include <iostream>
#include <string>

using std::string;

int main()
{
    int cases = 0;
    std::cin >> cases;
    while (cases--)
    {
        string rawCode, roastCode;
        std::cin >> rawCode;
        int len = rawCode.length();
        
        char nowChar = rawCode[0];
        int nowCount = 1;
        for (int i = 1; i < len; i++)
        {
            if (rawCode[i] == nowChar)
            {
                ++nowCount;
            }
            else
            {
                if (nowCount != 1)
                {
                    roastCode += std::to_string(nowCount);
                }
                roastCode += nowChar;
                nowChar = rawCode[i];
                nowCount = 1;
            }
        }
        if (nowCount != 1)
        {
            roastCode += std::to_string(nowCount);
        }
        roastCode += nowChar;
        nowChar = rawCode[len-1];
        nowCount = 1;
        std::cout << roastCode << std::endl;
    }
    
    return 0;
}