#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void getPathNumber(std::vector<std::vector<bool>> &space, std::vector<int> &pathNum,
                   int fromx, int fromy, int tox, int toy, std::string path, int &gcnt)
{
    bool isFull = true;
    bool start = space[fromx][fromy];
    for (int i = fromx; i < tox; ++i)
    {
        for (int j = fromy; j < toy; ++j)
        {
            if (space[i][j] != start)
            {
                isFull = false;
                goto LoopEnd;
            }
        }
    }
    LoopEnd: ;
    if (isFull)
    {
        if (start)
        {
            int val = 0;
            for (int i = 0, m = 1; i < path.size(); ++i, m *= 5)
            {
                val += (path[i]-'0') * m;
            }
            pathNum.push_back(val);
            ++gcnt;
        }
    }
    else
    {
        int midx = (fromx + tox) / 2;
        int midy = (fromy + toy) / 2;
        getPathNumber(space, pathNum, fromx, fromy, midx, midy, path+"1", gcnt);
        getPathNumber(space, pathNum, fromx, midy , midx, toy , path+"2", gcnt);
        getPathNumber(space, pathNum, midx , fromy, tox , midy, path+"3", gcnt);
        getPathNumber(space, pathNum, midx , midy , tox , toy , path+"4", gcnt);
    }
}

void paintSpace(std::vector<std::vector<bool>> &space, int val)
{
    int maxN = space.size();
    int fromx = 0, fromy = 0, tox = maxN, toy = maxN;
    while (val)
    {
        int p = val % 5;
        val /= 5;
        switch (p)
        {
        case 1:
            tox   = (fromx + tox) / 2;
            toy   = (fromy + toy) / 2;
            break;            
        case 2:
            tox   = (fromx + tox) / 2;
            fromy = (fromy + toy) / 2;
            break;
        case 3:
            fromx = (fromx + tox) / 2;
            toy   = (fromy + toy) / 2;
            break;
        case 4:
            fromx = (fromx + tox) / 2;
            fromy = (fromy + toy) / 2;
            break;
        default:
            break;
        }
    }
    for (int i = fromx; i < tox; ++i)
    {
        for (int j = fromy; j < toy; ++j)
        {
            space[i][j] = true;
        }
    }
}

int main()
{
    int cases = 0;
    int maxN;
    while (std::cin >> maxN && maxN)
    {
        if (cases)
        {
            std::cout << std::endl;
        }
        
        bool isGrid = (maxN > 0);
        if (maxN < 0)
        {
            maxN *= -1;
        }
        
        std::vector<std::vector<bool>> space(maxN, std::vector<bool>(maxN, false));
        std::vector<int> pathNumbers;
        
        if (isGrid)
        {
            getchar();
            for (int i = 0; i < maxN; ++i)
            {
                for (int j = 0; j < maxN; ++j)
                {
                    space[i][j] = getchar()-'0';
                }
                getchar();
            }
            int gridCount = 0;
            getPathNumber(space, pathNumbers, 0, 0, maxN, maxN, "", gridCount);
            std::sort(pathNumbers.begin(), pathNumbers.end());
            
            printf("Image %d\n", ++cases); 
            for (int i = 0; i < pathNumbers.size(); ++i)
            {
                printf("%d%c", pathNumbers[i], ( ( (i==pathNumbers.size()-1)||((i+1)%12==0) ) ? '\n' : ' ') );
            }
            printf("Total number of black nodes = %d\n", gridCount);
        }
        else
        {
            int val;
            while (std::cin >> val && val != -1)
            {
                paintSpace(space, val);
            }
            
            printf("Image %d\n", ++cases); 
            for (int i = 0; i < maxN; ++i)
            {
                for (int j = 0; j < maxN; ++j)
                {
                    std::cout << (space[i][j] ? '*' : '.') ;
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}