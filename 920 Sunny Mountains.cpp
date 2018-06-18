#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

struct point_type
{
    int x, y;
};

int main()
{
    int p;
    std::cin >> p;

    for (p; p > 0; --p)
    {
        int n;
        std::cin >> n;
        std::vector<point_type> v(n);

        for (int i = 0; i < n; ++i)
        {
            int x, y;
            std::cin >> x >> y;
            v[i] = point_type{x, y};
        }
        std::sort(v.begin(), v.end(), [](const point_type& lhs, const point_type& rhs){return lhs.x < rhs.x;});

        int max = v[n-1].y;
        double ans = 0;
        for (int i = n - 2; i >= 0; --i)
        {
            if (v[i].y > max)
            {
                ans += std::sqrt(std::pow(v[i].x - v[i + 1].x, 2) + std::pow(v[i].y - v[i + 1].y, 2)) * static_cast<double>(v[i].y - max) / (v[i].y - v[i + 1].y);
                max = v[i].y;
            }
        }
        std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
    }
}
