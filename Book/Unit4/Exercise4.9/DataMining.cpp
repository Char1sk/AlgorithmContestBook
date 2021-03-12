#include <iostream>
#include <cmath>

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    unsigned long long n, sp, sq;
    while (std::cin >> n >> sp >> sq)
    {
        long long minK = INT64_MAX, minA, minB;
        // std::cout << "m" << minK << std::endl;
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                if ( (sp + (sp << i)) >= (sq << j) && ( ( (n-1)*sp + (((n-1)*sp)<<i) ) >> j) + sq < minK)
                {
                    // std::cout << (sp + (sp << i)) << ' ' << (sq << j) << std::endl;
                    minK = ( ( ( (n-1)*sp + (((n-1)*sp)<<i) ) ) >> j) + sq;
                    minA = i;
                    minB = j;
                }
            }
        }
        std::cout << minK << ' ' << minA << ' ' << minB << std::endl;
    }
    return 0;
}


// Qi = Pi*(2^A+1)/2^B
// Min: mem = (n-1)*Sp*[(2^A+1)/2^B]+Sq
// Sp + Sp << A > Sq << B
// (2^A+1)/(2^B) > Sq / Sp
// (2^A+1)/(2^B) > 1