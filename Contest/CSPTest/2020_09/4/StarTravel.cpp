#include <iostream>
#include <vector>
#include <cmath>

const double PI = acos(-1);

inline double square(double x)
{
    return x*x;
}

double getDist(const std::vector<int> &p1, const std::vector<int> &p2)
{
    double ans = 0;
    for (int i = 0; i < p1.size(); ++i)
    {
        ans += square(p1[i]-p2[i]);
    }
    return std::sqrt(ans);
}

int main()
{
    int dim, pointCnt, radius;
    std::cin >> dim >> pointCnt >> radius;
    std::vector<int> blackhole(dim);
    for (int d = 0; d < dim; ++d)
    {
        std::cin >> blackhole[d];
    }
    std::vector<std::vector<int>> points(pointCnt, std::vector<int>(dim));
    for (int p = 0; p < pointCnt; ++p)
    {
        for (int d = 0; d < dim; ++d)
        {
            std::cin >> points[p][d];
        }
    }
    
    std::vector<std::vector<double>> dists(pointCnt, std::vector<double>(pointCnt));
    for (int i = 0; i < pointCnt-1; ++i)
    {
        for (int j = i+1; j < pointCnt; ++j)
        {
            double distij = getDist(points[i], points[j]);
            double distio = getDist(points[i], blackhole);
            double distjo = getDist(points[j], blackhole);
            // double cos = (square(distij)+square(distio)-square(distjo)) / (2*distij*distio);
            // double jio = acos(cos);
            double jio = acos((square(distij)+square(distio)-square(distjo)) / (2*distij*distio));
            double ijo = acos((square(distij)+square(distjo)-square(distio)) / (2*distij*distjo));
            double height = distio * sin(jio);
            if (height >= radius || jio >= PI/2 || ijo >= PI/2)
            {
                // no need to rewind
                dists[i][j] = distij;
                dists[j][i] = distij;
            }
            else
            {
                // must rewind
                double distia = std::sqrt(square(distio)-square(radius));
                double distib = std::sqrt(square(distjo)-square(radius));
                double ioj = acos((square(distio)+square(distjo)-square(distij)) / (2*distio*distjo));
                double ioa = acos(radius/distio);
                double job = acos(radius/distjo);
                double aob = ioj-ioa-job;
                double arc = radius * aob;
                double da = distia + distib + arc;
                dists[i][j] = da;
                dists[j][i] = da;
            }
        }
    }
    
    for (int i = 0; i < pointCnt; ++i)
    {
        double out = 0.0;
        for (int j = 0; j < pointCnt; ++j)
        {
            out += dists[i][j];
        }
        printf("%.14lf\n", out);
    }
    return 0;
}