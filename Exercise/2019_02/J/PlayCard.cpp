#include <iostream>
#include <string>

int main()
{
    std::string target;
    std::cin >> target;
    
    bool ok = false;
    for(int i = 0; i != 5; ++i)
    {
        std::string card;
        std::cin >> card;
        if(card[0] == target[0] || card[1] == target[1])
            ok = true;
    }
    std::cout << (ok ? "YES" : "NO") << std::endl;
    return 0;
}