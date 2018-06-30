#include <cstdio>
#include <array>
#include <bitset>

struct point_type
{
    int y;
    int x;
};

class island_type
{
  public:
    int const h, w;
    std::array<std::array<int, 52>, 52> map;
    std::array<point_type, 11> point;
    std::array<std::array<int, 11>, 11> adj;
    int point_num;

    island_type(int _h, int _w) : h(_h), w(_w)
    {
        for (int i = 0; i < h + 2; ++i)
        {
            map[i][0] = -10;
            map[i][w + 1] = -10;
        }
        for (int j = 0; j < w + 2; ++j)
        {
            map[0][j] = -10;
            map[h + 1][j] = -10;
        }
        for (int i = 0; i < 11; ++i)
        {
            for (int j = 0; j < 11; ++j)
            {
                adj[i][j] = 0;
            }
        }
    };

    void input()
    {
        point_num = 1;
        char temp[64];
        for (int i = 1; i <= h; ++i)
        {
            scanf("%s", temp);
            for (int j = 1; j <= w; ++j)
            {
                switch (temp[j - 1])
                {
                case '@':
                    point[0] = point_type{i, j};
                    map[i][j] = 0;
                    break;
                case '~':
                    map[i][j] = -1;
                    break;
                case '#':
                    map[i][j] = -96;
                    break;
                case '*':
                    map[i][j] = -99;
                    break;
                case '.':
                    map[i][j] = 0;
                    break;
                case '!':
                    point[point_num] = point_type{i, j};
                    point_num += 1;
                    map[i][j] = 0;
                    break;
                }
                //printf("i = %d j = %d c = %c d = %d\n", i, j, temp[j-1], map[i][j]);
            }
        }
    }

    void mask_around_natives()
    {
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                if (map[i][j] == -99)
                {
                    if (map[i - 1][j - 1] == 0)
                        map[i - 1][j - 1] = -98;
                    if (map[i - 1][j + 0] == 0)
                        map[i - 1][j + 0] = -98;
                    if (map[i - 1][j + 1] == 0)
                        map[i - 1][j + 1] = -98;
                    if (map[i + 0][j - 1] == 0)
                        map[i + 0][j - 1] = -98;
                    if (map[i + 0][j + 1] == 0)
                        map[i + 0][j + 1] = -98;
                    if (map[i + 1][j - 1] == 0)
                        map[i + 1][j - 1] = -98;
                    if (map[i + 1][j + 0] == 0)
                        map[i + 1][j + 0] = -98;
                    if (map[i + 1][j + 1] == 0)
                        map[i + 1][j + 1] = -98;
                }
            }
        }
    }

    void make_adj()
    {
        for (int t = 0; t < point_num; ++t)
        {
            auto temp_map = map;
            temp_map[point[t].y][point[t].x] = 1;
            int count = 1;
            while (count > 0)
            {
                count = 0;
                for (int i = 1; i <= h; ++i)
                {
                    for (int j = 1; j <= w; ++j)
                    {
                        if (temp_map[i][j] >= 0)
                        {
                            int const min = search_min(temp_map, i, j);
                            if (min != 0 && (temp_map[i][j] == 0 || temp_map[i][j] > min + 1))
                            {
                                temp_map[i][j] = min + 1;
                                count += 1;
                            }
                        }
                    }
                }
            }
            for (int k = 0; k < point_num; ++k)
            {
                adj[t][k] = temp_map[point[k].y][point[k].x] - 1;
            }
        }
    }

    void print_map(std::array<std::array<int, 52>, 52> thismap)
    {
        for (int i = 0; i < h + 2; ++i)
        {
            for (int j = 0; j < w + 2; ++j)
            {
                printf("%6d", thismap[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void print_adj()
    {
        for (int i = 0; i < point_num; ++i)
        {
            for (int j = 0; j < point_num; ++j)
            {
                printf("%3d", adj[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    void print_point()
    {
        for (int i = 0; i < point_num; ++i)
        {
            printf("y = %d x = %d\n", point[i].y, point[i].x);
        }
        printf("\n");
    }

    int solve()
    {
        if (point_num == 1)
        {
            return 0;
        }
        else if (can_solve() == false)
        {
            return -1;
        }
        std::bitset<11> visited(0);
        visited[0] = 1;
        return solvec(visited, 0, 0);
    }

  private:
    int solvec(std::bitset<11> &visited, int c, int pre_point)
    {
        int min = INT32_MAX;
        for (int i = 1; i < point_num; ++i)
        {
            if (visited[i] == 0)
            {
                if (visited.count() == point_num - 1)
                {
                    return c + adj[i][pre_point] + adj[i][0];
                }
                else
                {
                    visited[i] = 1;
                    int const temp = solvec(visited, c + adj[pre_point][i], i);
                    visited[i] = 0;
                    min = min > temp ? temp : min;
                }
            }
        }
        return min;
    }

    int search_min(std::array<std::array<int, 52>, 52> &temp_map, int y, int x)
    {
        int min = 5000;
        min = (min > temp_map[y - 1][x - 0] && temp_map[y - 1][x - 0] > 0) ? temp_map[y - 1][x - 0] : min;
        min = (min > temp_map[y - 0][x - 1] && temp_map[y - 0][x - 1] > 0) ? temp_map[y - 0][x - 1] : min;
        min = (min > temp_map[y - 0][x + 1] && temp_map[y - 0][x + 1] > 0) ? temp_map[y - 0][x + 1] : min;
        min = (min > temp_map[y + 1][x - 0] && temp_map[y + 1][x - 0] > 0) ? temp_map[y + 1][x - 0] : min;
        return min == 5000 ? 0 : min;
    }

    bool can_solve()
    {
        for (int i = 0; i < point_num; ++i)
        {
            for (int j = 0; j < point_num; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                else if (adj[i][j] <= 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    int h, w;
    int i = 1;
    while (scanf("%d %d", &h, &w) && h != 0 && w != 0)
    {
        island_type island(h, w);
        island.input();
        // island.print_point();
        // island.print_adj();
        // island.print_map(island.map);
        island.mask_around_natives();
        // island.print_map(island.map);
        island.make_adj();
        // island.print_adj();
        // printf("treasure num = %d\n", island.point_num);
        // printf("##########################################################\n");
        printf("%d\n", island.solve());
    }

    return 0;
}

