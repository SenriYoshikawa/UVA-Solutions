#include <cstdio>
#include <algorithm>
long long x, y;

long long gcd(long long a, long long b)
{
    return (a == 0 ? b : gcd(b % a, a));
}

long long egcd(long long a, long long b)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    } // stop condition
    long long d = egcd(b % a, a);
    long long tx = x; // gcd recurrence
    x = y - (b / a) * tx;
    y = tx;
    return d;
} // update x,y

int main()
{
    long long n;
    while (scanf("%lld", &n) == 1 && n)
    {
        long long c1, m1, c2, m2;
        scanf("%lld %lld %lld %lld", &c1, &m1, &c2, &m2);
        long long g = egcd(m1, m2);
        if (n % g != 0)
        {
            printf("failed\n");
            continue;
        }

        long long k = n / g;
        x *= k;
        y *= k;
        long long k1 = m2 / g;
        long long k2 = m1 / g;
        if (x < 0)
        {
            k = -x / k1 + (x % k1 == 0 ? 0 : 1);
            x += k * k1;
            y -= k * k2;
        }

        if (y < 0)
        {
            k = -y / k2 + (y % k2 == 0 ? 0 : 1);
            x -= k * k1;
            y += k * k2;
        }

        if (x < 0 || y < 0)
        {
            printf("failed\n");
            continue;
        }
        // printf("c1 = %lld m1 = %lld c2 = %lld m2 = %lld\n", c1, m1, c2, m2);
        // printf("a = %lld b = %lld\n", x, y);
        
        k = x / k1;
        long long x1 = x - k * k1;
        long long y1 = y + k * k2;
        k = y / k2;
        long long x2 = x + k * k1;
        long long y2 = y - k * k2;

        // printf("x1 = %lld y1 = %lld\n", x1, y1);
        // printf("x2 = %lld y2 = %lld\n", x2, y2);

        if (x1 * c1 + y1 * c2 < x2 * c1 + y2 * c2)
        {
            printf("%lld %lld\n", x1, y1);
        }
        else
        {
            printf("%lld %lld\n", x2, y2);
        }
    }
    return 0;
}
