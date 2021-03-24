#include <iostream>

void move(int n, int from, int to, const std::string &name)
{
    if (n > 0)
    {
        int mid = 3 - from - to;
        move(n-1, from, mid, name);
        printf("%d:%c->%c\n", n, name[from], name[to]);
        move(n-1, mid, to, name);
    }
}

int main()
{
    int count;
    std::string name(3, ' ');
    std::cin >> count >> name[0] >> name[1] >> name[2];
    
    move(count, 0, 2, name);
    
    return 0;
}