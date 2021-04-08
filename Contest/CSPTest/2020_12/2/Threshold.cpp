#include <iostream>
#include <map>
#include <set>

int main()
{
    int cnt;
    std::cin >> cnt;
    std::map<int, int> scoreToPass;
    std::map<int, int> scoreToFail;
    std::set<int> scores;
    int passCnt = 0;
    for (int i = 0; i < cnt; ++i)
    {
        int score;
        bool isPassed;
        std::cin >> score >> isPassed;
        scores.insert(score);
        if (isPassed)
        {
            ++passCnt;
            ++scoreToPass[score];
        }
        else
        {
            ++scoreToFail[score];
        }
    }
    
    int maxPrecision = 0;
    int maxThreshold = 0;
    int nowPrecision = passCnt;
    for (int s : scores)
    {
        int nowThreshold = s;
        if (nowPrecision >= maxPrecision)
        {
            maxPrecision = nowPrecision;
            maxThreshold = nowThreshold;
        }
        nowPrecision -= scoreToPass[s];
        nowPrecision += scoreToFail[s];
    }
    std::cout << maxThreshold << std::endl;
    return 0;
}