#include <iostream>
#include <vector>

struct Pair
{
    int idx;
    long long val;
};


int main()
{
    int dim, alen, blen;
    std::cin >> dim >> alen >> blen;
    std::vector<Pair> avec(alen), bvec(blen);
    for (int ai = 0; ai < alen; ++ai)
    {
        std::cin >> avec[ai].idx >> avec[ai].val;
    }
    for (int bi = 0; bi < blen; ++bi)
    {
        std::cin >> bvec[bi].idx >> bvec[bi].val;
    }
    int ai = 0, bi = 0;
    long long ans = 0;
    while (ai < alen && bi < blen)
    {
        if (avec[ai].idx < bvec[bi].idx)
        {
            ++ai;
        }
        else if (avec[ai].idx > bvec[bi].idx)
        {
            ++bi;
        }
        else
        {
            ans += avec[ai].val * bvec[bi].val;
            ++ai;
            ++bi;
        }
    }
    std::cout << ans << std::endl;
    
    return 0;
}