#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases = 0;
    int len, qCount;
    while ((std::cin >> len >> qCount) && (len || qCount))
    {
        std::vector<int> marbles;
        while (len--)
        {
            int itemp;
            std::cin >> itemp;
            marbles.push_back(itemp);
        }
        
        std::sort(marbles.begin(), marbles.end());
        
        printf("CASE# %d:\n", ++cases);
        while (qCount--)
        {
            int ans = -1;
            int qtemp;
            std::cin >> qtemp;
            for (int i = 0; i < marbles.size(); ++i)
            {
                if (marbles[i] == qtemp)
                {
                    ans = i+1;
                    break;
                }
            }
            if (ans != -1)
            {
                printf("%d found at %d\n", qtemp, ans);
            }
            else
            {
                printf("%d not found\n", qtemp);
            }
            
        }
        
    }
    return 0;
}