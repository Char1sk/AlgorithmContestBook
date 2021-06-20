#include <iostream>
#include <cstring>
#include <ctime>

// 编译参数，是否重定向和计时
#define USE_FILE
#define USE_TIMER

// 数据最大规模设置为10000
// 存储输入三角形的矩阵
const int maxN = 10000;
int maxSum[maxN][maxN];
int triangle[maxN][maxN];

// 测试时间用，仅用于Linux环境
#ifdef USE_TIMER
    void print_time_diff(timespec tbeg, timespec tend)
    {
        double timediff = 0.0;
        timediff += tend.tv_sec - tbeg.tv_sec;
        timediff += (tend.tv_nsec - tbeg.tv_nsec) / 1e9;
        printf("Passed %.9lf seconds\n", timediff);
    }
#endif

// 工具函数，获取较大者
inline int getMax(int a, int b)
{
    return (a > b ? a : b);
}

// DFS函数，用于回溯遍历
// r和c代表当前节点的行和列
// maxRow代表三角形的总行数
// 返回值代表r行c列的节点的最大可能和
int getMaxSum(const int r, const int c, const int maxRow)
{
    if (maxSum[r][c] == 0)
    {
        int ans = 0;
        int now = triangle[r][c];
        if (r == maxRow-1)
        {
            ans = now;
        }
        else
        {
            int leftSum = getMaxSum(r+1, c, maxRow);
            int rightSum = getMaxSum(r+1, c+1, maxRow);
            ans = now + getMax(leftSum, rightSum);
        }
        maxSum[r][c] = ans;
        return ans;
    }
    else
    {
        return maxSum[r][c];
    }
}

int main()
{
    // 重定向输入输出，文件后面的编号可更改
    // 第一个数字代表测试样例组数
    // 第二个代表解法编号，1为DFS，2为DP
    #ifdef USE_FILE
        freopen("./input4.txt", "r", stdin);
        freopen("./output41.txt", "w", stdout);
    #endif
    
    // 初始化输入的数组（其实不必要，输入过程会覆盖）
    memset(maxSum, 0, sizeof(maxSum));
    memset(triangle, 0, sizeof(triangle));
    // 读入输入
    int row;
    std::cin >> row;
    for (int r = 0; r < row; ++r)
    {
        for (int c = 0; c <= r; ++c)
        {
            std::cin >> triangle[r][c];
        }
    }
    
    // 记录开始时间
    #ifdef USE_TIMER
        timespec tbeg, tend;
        timespec_get(&tbeg, 1);
    #endif
    // 获取答案
    int ans = getMaxSum(0, 0, row);
    // 记录结束时间
    #ifdef USE_TIMER
        timespec_get(&tend, 1);
    #endif
    // 输出答案
    std::cout << ans << std::endl;
    // 输出总共耗时
    #ifdef USE_TIMER
        print_time_diff(tbeg, tend);
    #endif
    
    return 0;
}