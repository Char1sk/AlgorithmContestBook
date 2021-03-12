#include <iostream>
#include <cmath>

int main()
{
    int sum, pro;
    while(std::cin >> sum >> pro)
    {
        bool has = false;
        if(sum == 0 && pro == 0)
            break;
        for(int x = -1 * std::abs(sum); x <= std::abs(pro); ++x)
        {
            if((sum-x) * x == pro)
            {
                has = true;
                break;
            }
        }
        std::cout << (has ? "Yes" : "No") << std::endl;
    }
    return 0;
}
// x + y = s
// y = s - x
// xy = x(s-x) = p