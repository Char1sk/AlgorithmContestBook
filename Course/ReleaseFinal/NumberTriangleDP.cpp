#include <iostream>
#include <cstring>
#include <ctime>

// 编译参数，是否重定向和计时
#define USE_FILE
#define USE_TIMER

// 数据最大规模设置为10000
// 保存各节点状态，即该节点最大可能和
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

// DP函数，求解第一层节点的状态，即最大和
// maxRow代表三角形的总行数
void getMaxSum(const int maxRow)
{
    // 从最后一行开始计算状态
    for (int r = maxRow-1; r >= 0; --r)
    {
        // 一行之中，各列之间的状态没有直接关系
        for (int c = 0; c <= r; ++c)
        {
            // 最后一行的最大和即节点本身的值
            if (r == maxRow-1)
            {
                maxSum[r][c] = triangle[r][c];
            }
            // 该节点的最大和即为左右子节点和的较大者，加上自身的值
            else
            {
                maxSum[r][c] = triangle[r][c] + getMax(maxSum[r+1][c], maxSum[r+1][c+1]);
            }
        }
    }
}

int main()
{
    // 重定向输入输出，文件后面的编号可更改
    // 第一个数字代表测试样例组数
    // 第二个代表解法编号，1为DFS，2为DP
    #ifdef USE_FILE
        freopen("./input2.txt", "r", stdin);
        freopen("./output22.txt", "w", stdout);
    #endif
    
    // 初始化输入的数组（其实不必要，输入过程会覆盖）
    memset(maxSum, 0, sizeof(maxSum));
    memset(triangle, 0, sizeof(triangle));
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
    getMaxSum(row);
    // 记录结束时间
    #ifdef USE_TIMER
        timespec_get(&tend, 1);
    #endif
    // 输出答案
    std::cout << maxSum[0][0] << std::endl;
    // 输出总共耗时
    #ifdef USE_TIMER
        print_time_diff(tbeg, tend);
    #endif
    
    return 0;
}