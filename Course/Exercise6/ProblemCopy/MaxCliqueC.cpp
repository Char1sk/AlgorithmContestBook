#include <iostream>

using namespace std;

const int N = 50 + 5;
int n;
int G[N][N];
int vis[N]; // vis[i] means the number of i-th choosen vertex
int res;    // the count of max clique

// pos for vertexIndex, num for vertexIncluded
bool dfs(int pos, int num)
{
    // choose vertex that can join the clique
    for (int i = pos + 1; i <= n; i++)
    {
        if (G[pos][i])
        {
            int j;
            for (j = 0; j < num; j++)
                if (!G[i][vis[j]])
                    break;
            // success! it's a new vertex
            if (j == num)
            {
                vis[num] = i;
                if (dfs(i, num + 1))
                    return true;
            }
        }
    }
    
    // it's a valid path
    if (num > res)
    {
        res = num;
        return true;
    }
    // invalid instead
    return false;
}
void maxClique()
{
    res = -1;
    // for all vertex, No.n to No.1
    for (int i = n; i >= 1; i--)
    {
        vis[0] = i;
        dfs(i, 1);
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

        printf("%d\n", res);
    }
    return 0;
}