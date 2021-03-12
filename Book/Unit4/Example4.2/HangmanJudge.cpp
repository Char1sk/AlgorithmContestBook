#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int round;
    while ( (std::cin >> round) && (round != -1) )
    {
        std::string question;
        std::string answer;
        bool used[26] {0};
        bool isLive = false;
        bool isDead = false;
        int wrongCount = 0;
        std::cin >> question >> answer;
        int correctCount = 0;
        for (int i = 0; i < answer.length(); ++i)
        {
            int tempCount = std::count(question.begin(), question.end(), answer[i]);
            if ( (tempCount == 0) || (used[answer[i]-'a']) )
            {
                ++wrongCount;
            }
            else
            {
                used[answer[i]-'a'] = true;
                correctCount += tempCount;
            }
            if (wrongCount == 7)
            {
                isDead = true;
                break;
            }
            if (correctCount == question.length())
            {
                isLive = true;
                break;
            }
        }
        std::cout << "Round " << round << std::endl;
        if (isLive)
        {
            std::cout << "You win." << std::endl;
        }
        else if (isDead)
        {
            std::cout << "You lose." << std::endl;
        }
        else
        {
            std::cout << "You chickened out." << std::endl;
        }
        
    }
    return 0;
}