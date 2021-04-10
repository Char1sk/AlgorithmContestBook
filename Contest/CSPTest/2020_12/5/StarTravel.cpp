#include <iostream>
#include <vector>

typedef unsigned long long Integer;

inline Integer square(Integer i)
{
    return i * i;
}

struct Machine
{
    Integer x;
    Integer y;
    Integer z;
    Machine() : x(0), y(0), z(0) {}
};

int main()
{
    int sz, cmdCnt;
    std::cin >> sz >> cmdCnt;
    std::vector<Machine> machines(sz);
    while (cmdCnt--)
    {
        int cmd, left, right;
        std::cin >> cmd >> left >> right;
        --left; --right;
        int a, b, c, k;
        Integer distx = 0, disty = 0, distz = 0, ans = 0;
        switch (cmd)
        {
        case 1:
            std::cin >> a >> b >> c;
            for (int i = left; i <= right; ++i)
            {
                Machine &m = machines[i];
                m.x += a;
                m.y += b;
                m.z += c;
            }
            break;
        
        case 2:
            std::cin >> k;
            for (int i = left; i <= right; ++i)
            {
                Machine &m = machines[i];
                m.x *= k;
                m.y *= k;
                m.z *= k;
            }
            break;
        
        case 3:
            for (int i = left; i <= right; ++i)
            {
                Machine &m = machines[i];
                int temp = m.x;
                m.x = m.y;
                m.y = m.z;
                m.z = temp;
            }
            break;
        
        case 4:
            for (int i = left; i <= right; ++i)
            {
                Machine &m = machines[i];
                distx += m.x;
                disty += m.y;
                distz += m.z;
            }
            ans += square(distx);
            ans += square(disty);
            ans += square(distz);
            ans %= 1000000007;
            std::cout << ans << std::endl;
            break;
        
        default:
            break;
        }
    }
    return 0;
}