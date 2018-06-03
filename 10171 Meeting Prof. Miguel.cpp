#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    while (n > 0)
    {
        std::vector<std::vector<int>> miguel(26, std::vector<int>(26, 500 * 26));
        std::vector<std::vector<int>> mine(26, std::vector<int>(26, 500 * 26));

        for (n; n > 0; --n)
        {
            std::string a, s, x, y;
            int c, xi, yi;
            std::cin >> a >> s >> x >> y >> c;
            xi = static_cast<int>(x.c_str()[0] - 65);
            yi = static_cast<int>(y.c_str()[0] - 65);

            if (a == "Y")
            {
                mine[xi][yi] = c;
                if (s == "B")
                {
                    mine[yi][xi] = c;
                }
            }
            else
            {
                miguel[xi][yi] = c;
                if (s == "B")
                {
                    miguel[yi][xi] = c;
                }
            }
        }

        for (int k = 0; k < 26; ++k)
        {
            mine[k][k] = 0;
            miguel[k][k] = 0;
        }

        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    mine[i][j] = std::min(mine[i][j], mine[i][k] + mine[k][j]);
                    miguel[i][j] = std::min(miguel[i][j], miguel[i][k] + miguel[k][j]);
                }
            }
        }

        std::string a, b;
        std::cin >> a >> b;
        int ai = static_cast<int>(a.c_str()[0] - 65);
        int bi = static_cast<int>(b.c_str()[0] - 65);

        int ans_cost = 500 * 26;
        std::string ans = "";
        for (int k = 0; k < 26; ++k)
        {
            if (mine[ai][k] + miguel[bi][k] < ans_cost)
            {
                ans_cost = mine[ai][k] + miguel[bi][k];
                ans = static_cast<char>(k + 'A');
            }
            else if(mine[ai][k] + miguel[bi][k] == ans_cost && ans != "")
            {
                ans += " ";
                ans += static_cast<char>(k + 'A');
            }
        }

        if (ans != "")
        {
            std::cout << ans_cost << " " << ans << std::endl;
        }
        else
        {
            std::cout << "You will never meet." << std::endl;
        }

        std::cin >> n;
    }
    return 0;
}
