#include <cstdio>
#include <array>

std::array<std::array<int, 52>, 52> visited;
std::array<int, 52> cost;

int cut(int point_l, int point_r)
{
    if (visited.at(point_l).at(point_r))
    {
        return visited.at(point_l).at(point_r);
    }

    if (point_r - point_l == 1)
    {
        return 0;
    }

    int min = 1 << 30;
    for (int point_m = point_l + 1; point_m < point_r; ++point_m)
    {
        int temp = cost.at(point_r) - cost.at(point_l) +
                   cut(point_l, point_m) +
                   cut(point_m, point_r);
        min = min > temp ? temp : min;
    }
    return visited.at(point_l).at(point_r) = min;
}

int main()
{
    int l, n;
    while (scanf("%d", &l) && l > 0)
    {
        visited = std::array<std::array<int, 52>, 52>();
        cost = std::array<int, 52>();

        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &cost.at(i));
        }
        cost.at(n+1) = l;

        for (int i = 0; i < 50; ++i)
        {
            for (int j = 0; j < 50; ++j)
            {
                visited.at(i).at(j) = 0;
            }
        }
        printf("The minimum cutting is %d.\n", cut(0, n+1));
    }
    return 0;
}