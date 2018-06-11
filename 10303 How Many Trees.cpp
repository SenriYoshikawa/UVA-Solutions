#include <iostream>
#include <vector>

int main()
{
    std::vector<long long> data(1000, 0);
    data[1] = 1;
    for (int i = 2; i < 1000; ++i)
    {
        for (int j = 1; j < i - 1; ++j)
        {
            data[i] += data[j] * data[i - j - 1];
        }
        data[i] += data[i-1]*2;
    }

    int n;
    while(std::cin >> n)
    {
        std::cout << data[n] << std::endl;
    }
    return 0;
}