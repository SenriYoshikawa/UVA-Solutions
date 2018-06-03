#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    int p, r, problemno = 0;
    std::cin >> p >> r;
    while (p != 0 && r != 0)
    {
        int count = 0;
        std::map<std::string, int> map;
        std::vector<std::vector<int>> g(p, std::vector<int>(p, 3000));
        for (int i = 0; i < r; ++i)
        {
            std::string a, b;
            std::cin >> a >> b;

            if (map.find(a) == map.end())
            {
                map.insert(std::make_pair(a, count++));
            }

            if (map.find(b) == map.end())
            {
                map.insert(std::make_pair(b, count++));
            }

            g[map.find(a)->second][map.find(b)->second] = 1;
            g[map.find(b)->second][map.find(a)->second] = 1;
        }

        for (int i = 0; i < p; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                for (int k = 0; k < p; ++k)
                {
                    g[j][k] = std::min(g[j][k], g[j][i] + g[i][k]);
                }
            }
        }

        int max = 0;
        for (int i = 0; i < p; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                if(i == j)
                {
                    continue;
                }
                max = std::max(g[i][j], max);
            }
        }

        problemno++;
        if (max == 3000)
        {
            std::cout << "Network " << problemno << ": DISCONNECTED" << std::endl << std::endl;
        }
        else
        {
            std::cout << "Network " << problemno << ": " << max << std::endl << std::endl;
        }

        std::cin >> p >> r;
    }
    return 0;
}

