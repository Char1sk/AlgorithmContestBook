#include <iostream>
#include <vector>
#include <cmath>

const double maxN = 1000.0;

struct Ball
{
    double x;
    double y;
    double r;
    bool visited;
    Ball() : x(0), y(0), r(0), visited(false) {}
    Ball(double a, double b, double c) : x(a), y(b), r(c), visited(false) {}
};

std::vector<Ball> balls;
double leftMin = maxN;
double rightMin = maxN;

bool cross(const Ball &lhs, const Ball &rhs)
{
    double rsqr = (lhs.r + rhs.r) * (lhs.r + rhs.r);
    double dsqr = ((lhs.x - rhs.x) * (lhs.x - rhs.x)) + ((lhs.y - rhs.y) * (lhs.y - rhs.y));
    return rsqr >= dsqr;///
}

bool dfsUpDownThrough(Ball &start)
{
    start.visited = true;
    
    if (start.r >= start.y)///
    {
        return true;
    }
    
    for (auto &b : balls)
    {
        if (!b.visited && cross(start, b))
        {
            if (dfsUpDownThrough(b))
            {
                return true;
            }
        }
    }
    
    // check possible points
    if (start.r >= start.x)///
    {
        double nowy = start.y - std::sqrt((start.r * start.r) - (start.x * start.x));
        if (nowy < leftMin)
        {
            leftMin = nowy;
        }
    }
    if (start.r >= maxN - start.x)///
    {
        double deltax = maxN - start.x;
        double nowy = start.y - std::sqrt((start.r * start.r) - (deltax * deltax));
        if (nowy < rightMin)
        {
            rightMin = nowy;
        }
    }
    
    return false;
}

int main()
{
    // freopen("./in.txt", "r", stdin);
    // freopen("./out.txt", "w", stdout);
    
    int cases;
    while (std::cin >> cases)
    {
        balls.clear();
        leftMin = maxN;
        rightMin = maxN;
        
        while (cases--)
        {
            double x, y, r;
            std::cin >> x >> y >> r;
            balls.emplace_back(x, y, r);
        }
        
        bool canUpToDown = false;
        for (auto &b : balls)
        {
            if (!b.visited && maxN-b.y <= b.r)///
            {
                if (dfsUpDownThrough(b))
                {
                    canUpToDown = true;
                    break;
                }
            }
        }
        
        if (canUpToDown)
        {
            std::cout << "IMPOSSIBLE" << std::endl;
        }
        else
        {
            printf("%.2lf %.2lf %.2lf %.2lf\n", 0, leftMin, maxN, rightMin);
        }
        
        
    }
    return 0;
}