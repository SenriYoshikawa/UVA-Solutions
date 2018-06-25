#include <cstdio>
#include <cmath>

int main()
{
    long long  a, b, c;
    while (scanf("%lld %lld %lld", &a, &b, &c) == 3)
    {
        double s = (a + b + c) / 2.0;
        double tris = std::sqrt(s * (s - a) * (s - b) * (s - c));
        double rose = (s - a) * (s - b) * (s - c) * M_PI / s;
        double vio = tris - rose;
        double sun = M_PI * std::pow(a * b * c / 4.0 / tris, 2) - tris;
        printf("%.4lf %.4lf %.4lf\n", sun, vio, rose);
    }
    return 0;
}
