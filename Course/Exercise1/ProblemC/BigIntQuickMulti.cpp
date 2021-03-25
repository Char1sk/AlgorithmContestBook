#include <iostream>
#include <string>
#include <list>

struct BigInteger
{
    std::list<int> val;
    int digits;
    BigInteger() : val(), digits(0) {}
    BigInteger(const std::string &s) : digits(s.size())
    {
        for (char c : s)
        {
            val.push_back(c-'0');
        }
    }
    BigInteger(const std::list<int> &li) : val(li), digits(li.size()) {}
    BigInteger(const std::list<int> &li, int from, int to) : digits(to-from)
    {
        auto it = li.begin();
        for (int i = 0; i < from; ++i)
        {
            ++it;
        }
        for (int i = from; i < to; ++i)
        {
            val.push_back(*it);
            ++it;
        }
    }
    BigInteger addZero(int n)
    {
        BigInteger ret(*this);
        for (int i = 0; i < n; ++i)
        {
            ret.val.push_back(0);
            ++ret.digits;
        }
        return ret;
    }
    BigInteger &operator+= (const BigInteger &bint)
    {
        auto it = val.rbegin();
        auto jt = bint.val.rbegin();
        int carry = 0;
        while (it != val.rend() && jt != bint.val.rend())
        {
            int v = *it + *jt + carry;
            carry = v / 10;
            *it = v - 10*carry;
            ++it;   ++jt;
        }
        while (it != val.rend())
        {
            int v = *it + carry;
            carry = v / 10;
            *it = v - 10*carry;
            ++it;
        }
        while (jt != bint.val.rend())
        {
            int v = *jt + carry;
            carry = v / 10;
            val.push_front(v - 10*carry);
            ++digits;
            ++jt;
        }
        if (carry)
        {
            val.push_front(carry);
            ++digits;
        }
        return *this;
    }
};

BigInteger operator* (const BigInteger &bi, int t)
{
    std::list<int> li;
    int carry = 0;
    for (auto it = bi.val.rbegin(); it != bi.val.rend(); ++it)
    {
        int now = *it * t + carry;
        carry = now / 10;
        li.push_front(now - 10*carry);
    }
    if (carry)
    {
        li.push_front(carry);
    }
    return BigInteger(li);
}

BigInteger operator* (const BigInteger &lhs, const BigInteger &rhs)
{
    if (lhs.digits == 1)
    {
        return rhs * lhs.val.front();
    }
    if (rhs.digits == 1)
    {
        return lhs * rhs.val.front();
    }
    int lhIndex = lhs.digits/2;
    int rhIndex = rhs.digits/2;
    int lhDigit = lhs.digits-lhIndex;
    int rhDigit = rhs.digits-rhIndex;
    BigInteger lh(lhs.val, 0, lhIndex);
    BigInteger ll(lhs.val, lhIndex, lhs.digits);
    BigInteger rh(rhs.val, 0, rhIndex);
    BigInteger rl(rhs.val, rhIndex, rhs.digits);
    BigInteger ret;
    ret += (lh * rh).addZero(lhDigit + rhDigit);
    ret += (lh * rl).addZero(lhDigit);
    ret += (rh * ll).addZero(rhDigit);
    ret += (ll * rl);
    return ret;
    // lhs = lh * (10, lhDigit) + ll;
    // rhs = rh * (10, rhDigit) + rl;
    // ret = lh * rh * (10, lhDigit+rhDigit)
    //     + lh * rl * (10, lhDigit)
    //     + rh * ll * (10, rhDigit)
    //     + rl * ll ;
}

std::ostream &operator<< (std::ostream &os, const BigInteger &bint)
{
    for (int i : bint.val)
    {
        os << i;
    }
    return os;
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;
    BigInteger bint1(s1), bint2(s2);
    std::cout << bint1 * bint2 << std::endl;
    return 0;
}