// #pragma G++ optimize("O2")

#include <iostream>
// #include <vector>
#include <cstring>
#include <algorithm>

class Country
{
public:
    int gold;
    int medal;
    int total;
    int order;
    int rank;
    Country(int a = 0, int b = 0, int c = 0, int o = 0) : 
            gold(a), medal(b), total(c), order(o) {}
};

bool sortA(const Country &c1, const Country &c2)
{
    return c1.gold > c2.gold;
}
bool sortB(const Country &c1, const Country &c2)
{
    return c1.medal > c2.medal;
}
bool sortC(const Country &c1, const Country &c2)
{
    return 1.0*c1.gold/c1.total > 1.0*c2.gold/c2.total;
}
bool sortD(const Country &c1, const Country &c2)
{
    return 1.0*c1.medal/c1.total > 1.0*c2.medal/c2.total;
}

void rankA(Country cvec[], int n)
{
    int r = 1;
    for(int i = 0; i != n; ++i, ++r)
    {
        if(i != 0 && cvec[i].gold == cvec[i-1].gold)
            cvec[i].rank = cvec[i-1].rank;
        else
            cvec[i].rank = r;
    }
}
void rankB(Country cvec[], int n)
{
    int r = 1;
    for(int i = 0; i != n; ++i, ++r)
    {
        if(i != 0 && cvec[i].medal == cvec[i-1].medal)
            cvec[i].rank = cvec[i-1].rank;
        else
            cvec[i].rank = r;
    }
}
void rankC(Country cvec[], int n)
{
    int r = 1;
    for(int i = 0; i != n; ++i, ++r)
    {
        if(i != 0 && 1.0*cvec[i].gold/cvec[i].total == 1.0*cvec[i-1].gold/cvec[i-1].total)
            cvec[i].rank = cvec[i-1].rank;
        else
            cvec[i].rank = r;
    }
}
void rankD(Country cvec[], int n)
{
    int r = 1;
    for(int i = 0; i != n; ++i, ++r)
    {
        if(i != 0 && 1.0*cvec[i].medal/cvec[i].total == 1.0*cvec[i-1].medal/cvec[i-1].total)
            cvec[i].rank = cvec[i-1].rank;
        else
            cvec[i].rank = r;
    }
}

typedef bool (*sortp)(const Country &, const Country &);
typedef void (*rankp)(Country [], int);


int main()
{
    sortp sorts[4] = {sortA, sortB, sortC, sortD};
    rankp ranks[4] = {rankA, rankB, rankC, rankD};
    int n, m;
    while(std::cin >> n >> m)
    {
        Country cvec[300];
        // n
        for(int i = 0; i != n; ++i)
        {
            std::cin >> cvec[i].gold >> cvec[i].medal >> cvec[i].total;
            cvec[i].order = i;
        }
        int nums[300];
        // m
        for(int i = 0; i != m; ++i)
        {
            std::cin >> nums[i];
        }
        Country plans[4][300] = {{}, {}, {}, {}};
        // 4m
        for(int i = 0; i != 4; ++i)
        {
            for(int j = 0; j != m; ++j)
            {
                plans[i][j] = cvec[nums[j]];
            }
        }
        // 4m
        int min_rank[300];
        memset(min_rank, 127, 300*sizeof(int));
        int min_plan[300] = {0};
        for(int i = 0; i != 4; ++i)
        {
            std::sort(plans[i], plans[i]+m, sorts[i]);
            ranks[i](plans[i], m);
            for(int j = 0; j != m; ++j)
            {
                // std::cout << plans[i][j].order << ':' << plans[i][j].rank << ';';
                if(min_rank[plans[i][j].order] > plans[i][j].rank)
                {
                    min_rank[plans[i][j].order] = plans[i][j].rank;
                    min_plan[plans[i][j].order] = i+1;
                    // std::cout << min_rank[plans[i][j].order] << ':' << min_plan[plans[i][j].order] << "; " ;
                }
            }
            // std::cout << std::endl;
        }
        // m
        for(int i = 0; i != m; ++i)
        {
            std::cout << min_rank[nums[i]] << ':' << min_plan[nums[i]] << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}