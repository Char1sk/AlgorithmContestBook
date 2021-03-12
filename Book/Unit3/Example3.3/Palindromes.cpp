#include <iostream>
#include <string>

char getMirroredChar(char c)
{
    const std::string mirrorString("A***3**HIL*JM*O***2TUVWXY51SE*Z**8*");
    if (isalpha(c))
    {
        return mirrorString[c-'A'];
    }
    else
    {
        return mirrorString[c-'0'+25];
    }
    // switch (c)
    // {
    // case 'A':
    // case 'H':
    // case 'I':
    // case 'M':
    // case 'O':
    // case 'T':
    // case 'U':
    // case 'V':
    // case 'W':
    // case 'X':
    // case 'Y':
    // case '1':
    // case '8':
    //     return c;
    // case 'E':
    //     return '3';
    // case 'J':
    //     return 'L';
    // case 'L':
    //     return 'J';
    // case 'S':
    //     return '2';
    // case 'Z':
    //     return '5';
    // case '2':
    //     return 'S';
    // case '3':
    //     return 'E';
    // case '5':
    //     return 'Z';
    // default:
    //     return '*';
    // }
}

int main()
{
    std::string line;
    while (std::cin >> line)
    {
        bool isPalindrome = true;
        bool isMirrored = true;
        for (int i = 0; i <= line.size()/2; ++i)
        {
            if (line[i] != line[line.size()-i-1])
            {
                isPalindrome = false;
            }
            if (line[i] != getMirroredChar(line[line.size()-i-1]))
            {
                isMirrored = false;
            }
            if (!isPalindrome && !isMirrored)
            {
                break;
            }
        }
        if (!isPalindrome && !isMirrored)
        {
            std::cout << line << " -- is not a palindrome." << std::endl << std::endl;
        }
        if ( isPalindrome && !isMirrored)
        {
            std::cout << line << " -- is a regular palindrome." << std::endl << std::endl;
        }
        if (!isPalindrome &&  isMirrored)
        {
            std::cout << line << " -- is a mirrored string." << std::endl << std::endl;
        }
        if ( isPalindrome &&  isMirrored)
        {
            std::cout << line << " -- is a mirrored palindrome." << std::endl << std::endl;
        }
    }   
    return 0;
}