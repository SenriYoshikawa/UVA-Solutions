#include <iostream>
#include <vector>
#include <cmath>

int n, x;
std::vector<std::vector<uint64_t>> memo;

uint64_t gcd(uint64_t n, uint64_t m)
{
    return m == 0 ? n : gcd(m, n % m);
}

uint64_t rec(int cd, int sum)
{
    if (cd == 0)
    {
        if (x <= sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (memo[cd][sum] != -1)
    {
        return memo[cd][sum];
    }

    uint64_t ans = 0;
    for (int i = 1; i < 7; ++i)
    {
        ans += rec(cd - 1, sum + i);
    }
    memo[cd][sum] = ans;
    
    return ans;
}

int main()
{
    std::cin >> n >> x;

    while (n != 0 || x != 0)
    {
        memo = std::vector<std::vector<uint64_t>>(25, std::vector<uint64_t>(150, -1));
        uint64_t denominator = std::pow(6, n);
        uint64_t numerator = rec(n, 0);
        uint64_t gcdi = gcd(numerator, denominator);
        denominator /= gcdi;
        numerator /= gcdi;
        if (denominator == 1)
        {
            std::cout << numerator << std::endl;
        }
        else
        {
            std::cout << numerator << "/" << denominator << std::endl;
        }
        std::cin >> n >> x;
    }

    return 0;
}
