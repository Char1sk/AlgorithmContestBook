#include <iostream>

using namespace std;

const int N = 50 + 5;
int n;
int G[N][N];
int cnt[N]; //cnt[i]为>=i的最大团点数
int vis[N]; //记录点的位置
int res;    //最大团的数目
bool dfs(int pos, int num)
{ //num为已取的点数
    for (int i = pos + 1; i <= n; i++)
    {
        if (cnt[i] + num <= res) //剪枝，若取i但cnt[i]+已经取了的点数仍<ans
            return false;

        if (G[pos][i])
        { //与当前团中元素比较，取Non-N(i)
            int j;
            for (j = 0; j < num; j++)
                if (!G[i][vis[j]])
                    break;
            if (j == num)
            { //若为空，则皆与i相邻，则此时将i加入到最大团中
                vis[num] = i;
                if (dfs(i, num + 1))
                    return true;
            }
        }
    }

    if (num > res)
    {              //每添加一个点最多使最大团数+1,后面的搜索就没有意义了
        res = num; //最大团中点的数目
        return true;
    }
    return false;
}
void maxClique()
{
    res = -1;
    for (int i = n; i >= 1; i--)
    { //枚举所有点
        vis[0] = i;
        dfs(i, 1);
        cnt[i] = res;
    }
}
int main()
{
    while (scanf("%d", &n) != EOF && (n))
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &G[i][j]);
        maxClique();

        printf("%d\n", res); //最大团的个数
    }
    return 0;
}