#include <iostream>
#include <map>

int main()
{
    int cases = 0;
    int row, col;
    while ((std::cin >> row >> col) && row && col)
    {
        std::map<int, int> grids;
        for (int i = 0; i < row*col; ++i)
        {
            int itemp;
            std::cin >> itemp;
            ++grids[itemp];
        }
        
        double water;
        std::cin >> water;
        
        int coveredGrids = 0;
        int lastLevel;
        int nowLevel;
        double deltaLevel = 0.0;
        for (auto it = grids.begin(); it != grids.end() && water > 0; ++it)
        {
            if (it == grids.begin())
            {
                lastLevel = it->first;
                coveredGrids += it->second;
            }
            else
            {
                nowLevel = it->first;
                
                if (water > (nowLevel-lastLevel)*100*coveredGrids)
                {
                    water -= (nowLevel-lastLevel)*100*coveredGrids;
                    coveredGrids += it->second;
                    lastLevel = nowLevel;
                }
                else
                {
                    deltaLevel = water / (100*coveredGrids);
                    water = 0;
                }
            }
        }
        if (water > 0)
        {
            deltaLevel = water / (100*coveredGrids);
            water = 0;
        }
        
        printf("Region %d\n", ++cases);
        printf("Water level is %.2lf meters.\n", lastLevel + deltaLevel);
        printf("%.2lf percent of the region is under water.\n", 100.0 * coveredGrids / (row*col));
        std::cout /* << lastLevel << ' ' << deltaLevel */ << std::endl;
    }
    return 0;
}