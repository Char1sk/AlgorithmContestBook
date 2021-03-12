#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s1, s2;
    while(std::cin >> s1 >> s2)
    {
        std::vector<char> v1(s1.rbegin(), s1.rend());
        std::vector<char> v2(s2.rbegin(), s2.rend());
        
        std::vector<int> v;
        int carry = 0;
        int i;
        for(i = 0; i != v1.size() && i != v2.size(); ++i)
        {
            int sum = carry + v1[i] + v2[i] - '0' - '0';
            carry = sum / 10;
            v.push_back(sum % 10);
        }
        if(i == v1.size() && i < v2.size())
            for( ; i < v2.size(); ++i)
            {
                int sum = carry + v2[i] - '0';
                carry = sum / 10;
                v.push_back(sum % 10);
            }
        else if(i < v1.size() && i == v2.size())
            for( ; i < v1.size(); ++i)
            {
                int sum = carry + v1[i] - '0';
                carry = sum / 10;
                v.push_back(sum % 10);
            }
        if(carry)
            v.push_back(carry);
        for(auto rb = v.rbegin(); rb != v.rend(); ++rb)
            std::cout << *rb;
        std::cout << std::endl;
    }
    return 0;
}