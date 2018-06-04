#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    while (std::cin >> n)
    {
        std::vector<int> diff;
        int a, b;
        if(n == 1)
        {
            std::cout << "Jolly" << std::endl;
            std::cin >> n;
            continue;    
        }
        std::cin >> a;
        for (n; n > 1; --n)
        {
            std::cin >> b;
            diff.push_back(std::abs(a - b));
            a = b;
        }
        std::sort(diff.begin(), diff.end());
        bool jolly = true;
        for(int i = 0; i < diff.size(); ++i)
        {
            if(diff.at(i) != i + 1)
            {
                jolly = false;
                break;
            }
        }
        if(jolly == true)
        {
            std::cout << "Jolly" << std::endl;
        }
        else
        {
            std::cout << "Not jolly" << std::endl;
        }
    }
}
