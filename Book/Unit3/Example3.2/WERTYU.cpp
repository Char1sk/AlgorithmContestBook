#include <iostream>
#include <string>

int main()
{
    const std::string keyboard("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./");
    int tempChar;
    while ( (tempChar = getchar()) != EOF)
    {
        char ch = tempChar;
        long long idx = keyboard.find(ch);
        if (idx != std::string::npos)
        {
            std::cout << keyboard[keyboard.find(ch)-1];
        }
        else
        {
            std::cout << ch;
        }
        
        // int i;
        // for (i = 1; keyboard[i] && keyboard[i] != tempChar; ++i) ;
        //     if (keyboard[i])
        //         putchar(keyboard[i-1]);
        //     else
        //         putchar(tempChar);
    }
    return 0;
}