#include <iostream>
#include <vector>
#include <cstring>

int main()
{
    int game = 0;
    int len;
    while ( (std::cin >> len) && len )
    {
        int *answer = new int[len];
        int *guess = new int[len];
        memset(guess, 1, sizeof(int)*len);
        for (int i = 0; i < len; ++i)
        {
            std::cin >> answer[i] ;
        }
        
        printf("Game %d:\n", ++game);
        while (true)
        {
            bool isBreak = false;
            for (int i = 0; i < len; ++i)
            {
                std::cin >> guess[i] ;
                isBreak = isBreak || guess[i];
            }
            if (!isBreak)
            {
                break;
            }
            
            int strong = 0;
            int weak = 0;
            int answerSta[10] {0};
            int guessSta[10] {0};
            for (int i = 0; i < len; ++i)
            {
                ++answerSta[answer[i]];
                ++guessSta[guess[i]];
                if (answer[i] == guess[i])
                {
                    ++strong;
                }
            }
            for (int i = 1; i < 10; ++i)
            {
                weak += (answerSta[i] < guessSta[i]) ? answerSta[i] : guessSta[i] ;
            }
            weak -= strong;
            printf("    (%d,%d)\n", strong, weak);
        }
        delete[] answer;
        delete[] guess;
    }
    return 0;
}