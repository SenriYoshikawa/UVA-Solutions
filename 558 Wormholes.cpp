#include <iostream>
#include <vector>
#include <bitset>
#include <string>

struct edge
{
    int from, to, time;
};

int main()
{
    int p;
    std::cin >> p;
    for (p; p > 0; --p)
    {
        int s, w;
        std::cin >> s >> w;
        std::vector<edge> edges(w);

        for (int i = 0; i < w; ++i)
        {
            int a, b, t;
            std::cin >> a >> b >> t;
            edges[i] = edge{a, b, t};
        }

        std::bitset<1000> visited(0);
        std::vector<int> subtime(s, 0);
        visited[0] = 1;
        for (int i = 0; i < s - 1; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (visited[edges[j].from] == 1)
                {
                    if (visited[edges[j].to] == 0)
                    {
                        subtime[edges[j].to] = subtime[edges[j].from] + edges[j].time;
                        visited[edges[j].to] = 1;
                    }
                    else if (subtime[edges[j].to] > subtime[edges[j].from] + edges[j].time)
                    {
                        subtime[edges[j].to] = subtime[edges[j].from] + edges[j].time;
                    }
                }
            }
        }

        bool found = false;
        for (int i = 0; i < w; ++i)
        {
            if(subtime[edges[i].to] > subtime[edges[i].from] + edges[i].time)
            {
                found = true;
                break;
            }
        }

        std::cout << (found ? "possible" : "not possible") << std::endl;
    }
    return 0;
}

