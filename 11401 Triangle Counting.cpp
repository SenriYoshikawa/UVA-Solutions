#include <cstdio>
#include <array>

int main()
{
    std::array<long long, 1000005> a;
    a[4] = 1;
    a[5] = 3;
    for (long long i = 6; i <= 1000000; i++)
    // for (int i = 6; i <= 10; i++)
    {
        // n = even
        a[i] = a[i - 1] + ((i - 2) / 2 * (1 + (i - 3)) / 2);
        // printf("%d %d %d %d \n", (i - 2) / 2, 1, (i - 3), ((i - 2) / 2 * (1 + (i - 3)) / 2));
        // printf("a[%d] = %lld   %d\n", i, a[i], ((i - 2) / 2 * (1 + (i - 3)) / 2));
        ++i;
        // n = odd
        // printf("%d\n", i);
        a[i] = a[i - 1] + (i - 2) / 2 * (2 + (i - 3)) / 2;
        // printf("a[%d] = %lld   %d\n", i, a[i], (i - 2) / 2 * (2 + (i - 3)) / 2);
    }

    long long n;
    while (scanf("%llu", &n) && n > 2)
    {
        printf("%llu\n", a[n]);
    }
    return 0;
}
