#include <iostream>

bool read(int &w)
{
    int lw, ll, rw, rl;
    std::cin >> lw >> ll >> rw >> rl;
    
    bool b1 = true, b2 = true;
    if (lw == 0)
    {
        b1 = read(lw);
    }
    if (rw == 0)
    {
        b2 = read(rw);
    }
    
    w = lw + rw;
    return b1 && b2 && (lw * ll == rw * rl);
}

int main()
{
    int cases;
    std::cin >> cases;
    while (cases--)
    {
        int temp;
        std::cout << ( read(temp) ? "YES" : "NO" ) << std::endl;
        if (cases)
            std::cout << std::endl;
    }
    return 0;
}