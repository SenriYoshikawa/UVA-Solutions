#include <cstdio>
#include <string.h>
#include <algorithm>

int acorn[2005][2005];
int dp[2005];

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int t, h, f;
        memset(acorn, 0, sizeof(acorn));
        memset(dp, 0, sizeof(dp));

        scanf("%d %d %d", &t, &h, &f);

        for (int i = 0; i < t; ++i) 
        {
            int k, p;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &p);
                acorn[i][p] += 1;
            }
        }

        for (int i = 0; i <= h; ++i)
        {
            for (int j = 0; j < t; ++j)
            {
                dp[i] = std::max(dp[i], acorn[j][i]);
            }
        }

        for (int i = h - 1; i >= 0; --i)
        {
            for (int j = 0; j < t; ++j)
            {
                acorn[j][i] += std::max(acorn[j][i + 1], i + f <= h ? dp[i + f] : 0);
                dp[i] = std::max(dp[i], acorn[j][i]);
            }
        }
        printf("%d\n", dp[0]);
    }
    scanf("%d", &n);
    return 0;
}