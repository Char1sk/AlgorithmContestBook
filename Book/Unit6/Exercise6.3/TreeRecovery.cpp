#include <iostream>
#include <string>
#include <vector>

int buildTree(const std::string &pre, const std::string &in,
               std::vector<int> &l, std::vector<int> &r,
               int pl, int pr, int il, int ir)
{
    if (pl != pr)
    {
        int rootIdx = pre[pl]-'A';
        int inRootIdx = in.find(pre[pl]);
        int leftCnt = inRootIdx-il;
        int lroot = buildTree(pre, in, l, r, pl+1, pl+1+leftCnt, il, inRootIdx);
        int rroot = buildTree(pre, in, l, r, pl+1+leftCnt, pr, inRootIdx+1, ir);
        l[rootIdx] = lroot;
        r[rootIdx] = rroot;
        return rootIdx;
    }
    else
    {
        return -1;
    }
    
}

void postOut(const std::vector<int> &l, const std::vector<int> &r, int idx)
{
    if (l[idx] != -1)
    {
        postOut(l, r, l[idx]);
    }
    if (r[idx] != -1)
    {
        postOut(l, r, r[idx]);
    }
    std::cout << char(idx+'A');
}

int main()
{
    std::string preOrder;
    std::string inOrder;
    while (std::cin >> preOrder >> inOrder)
    {
        int len = preOrder.size();
        std::vector<int> left(26, -1);
        std::vector<int> right(26, -1);
        buildTree(preOrder, inOrder, left, right, 0, len, 0, len);
        postOut(left, right, preOrder.front()-'A');
        std::cout << std::endl;
    }
}