#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

const int maxN = 1000+5;
const int maxV = maxN * maxN * maxN;
const int directions[6][3]{
    {-1, 0, 0}, {1, 0, 0},
    {0, -1, 0}, {0, 1, 0},
    {0, 0, -1}, {0, 0, 1}
};

struct Node
{
    int xlen, ylen, zlen;
    char flag;
    Node(int ii = 0, int jj = 0, int kk = 0) : xlen(ii), ylen(jj), zlen(kk), flag(0) {}
};

Node space[105][105][105];

void dfsFlood(int idx1, int idx2, int idx3, int len1, int len2, int len3, int &v, int &s)
{
    Node &now = space[idx1][idx2][idx3];
    now.flag = 2;
    v += now.xlen * now.ylen * now.zlen;
    // std::cout << "v:" << v << std::endl;////
    
    for (int i = 0; i < 6; ++i)
    {
        auto nextidx1 = idx1 + directions[i][0];
        auto nextidx2 = idx2 + directions[i][1];
        auto nextidx3 = idx3 + directions[i][2];
        if (0 <= nextidx1 && nextidx1 < len1 &&
            0 <= nextidx2 && nextidx2 < len2 &&
            0 <= nextidx3 && nextidx3 < len3)
        {
            Node &next = space[nextidx1][nextidx2][nextidx3];
            if (next.flag == 1)
            {
                if (i == 0 || i == 1)
                {
                    s += next.ylen * next.zlen;
                }
                if (i == 2 || i == 3)
                {
                    s += next.xlen * next.zlen;
                }
                if (i == 4 || i == 5)
                {
                    s += next.xlen * next.ylen;
                }
                // std::cout << "s:" << s << std::endl;////
            }
            if (next.flag == 0)
            {
                dfsFlood(nextidx1, nextidx2, nextidx3, len1, len2, len3, v, s);
            }
        }
    }
    
    // if (idx1 == 0 && idx2 == 0 && idx3 == 0)
    // {
    //     std::cout << "?????" << std::endl;
    //     int a;
    //     std::cin >> a;
    // }
}

int main()
{
    int cases;

    std::cin >> cases;
    while (cases--)
    {
        for (int i = 0; i < 105; ++i)
        {
            for (int j = 0; j < 105; ++j)
            {
                for (int k = 0; k < 105; ++k)
                {
                    space[i][j][k].flag = 0;
                }
            }
        }
        
        int boxCnt;
        std::cin >> boxCnt;
        
        std::vector<std::vector<int>> input;
        std::map<int, int> cordToIndex[3];
        std::set<int> cords[3];
        for (int i = 0; i < 3; ++i)
        {
            cords[i].insert(0);
            cords[i].insert(maxN);
        }
        while (boxCnt--)
        {
            std::vector<int> line;
            int pos[3], len[3];
            for (int i = 0; i < 3; ++i)
            {
                std::cin >> pos[i];
                line.push_back(pos[i]);
                cords[i].insert(pos[i]);
            }
            for (int i = 0; i < 3; ++i)
            {
                std::cin >> len[i];
                line.push_back(len[i]);
                cords[i].insert(pos[i]+len[i]);
            }
            input.push_back(line);
        }
        
        int idx1 = 0, idx2 = 0, idx3 = 0;
        for (auto xit = cords[0].begin(); xit != cords[0].end(); ++xit, ++idx1)
        {
            if (*xit == maxN)
                break;
            idx2 = 0;
            for (auto yit = cords[1].begin(); yit != cords[1].end(); ++yit, ++idx2)
            {
                if (*yit == maxN)
                    break;
                idx3 = 0;
                for (auto zit = cords[2].begin(); zit != cords[2].end(); ++zit, ++idx3)
                {
                    if (*zit == maxN)
                        break;
                    Node &now = space[idx1][idx2][idx3];
                    cordToIndex[0][*xit] = idx1;
                    cordToIndex[1][*yit] = idx2;
                    cordToIndex[2][*zit] = idx3;
                    ++xit; ++yit; ++zit;
                    now.xlen = *xit;
                    now.ylen = *yit;
                    now.zlen = *zit;
                    --xit; --yit; --zit;
                    now.xlen -= *xit;
                    now.ylen -= *yit;
                    now.zlen -= *zit;
                    // now.flag = 1;
                }
            }
        }
        
        for (auto &line : input)
        {
            for (int i = cordToIndex[0][line[0]]; i < cordToIndex[0][line[0]+line[3]]; ++i)
            {
                for (int j = cordToIndex[1][line[1]]; j < cordToIndex[1][line[1]+line[4]]; ++j)
                {
                    for (int k = cordToIndex[2][line[2]]; k < cordToIndex[2][line[2]+line[5]]; ++k)
                    {
                        space[i][j][k].flag = 1;
                    }
                }
            }
        }
        
        int s = 0;
        int v = 0;
        dfsFlood(0, 0, 0, idx1, idx2, idx3, v, s);
        
        std::cout << s << ' ' << (maxV-v) << std::endl;
    }
    return 0;
}
