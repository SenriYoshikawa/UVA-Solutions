#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int a, b;
    while (std::cin >> a >> b)
    {
        std::vector<int> a_vec(a);
        std::vector<int> b_vec(b);
        if (a == 0 && b == 0)
        {
            break;
        }

        for(int i = 0; i < a; ++i)
        {
            int temp;
            std::cin >> temp;
            a_vec[i] = temp;
        }

        for(int i = 0; i < b; ++i)
        {
            int temp;
            std::cin >> temp;
            b_vec[i] = temp;

        }

        std::sort(a_vec.begin(), a_vec.end());
        std::sort(b_vec.begin(), b_vec.end());
        
        int count = 0;
        for(std::size_t i = 0, j = 0; i < a && j < b;)
        {
            if(a_vec[i] == b_vec[j])
            {
                count++;
                i++;
                j++;
            }
            else if(a_vec[i] < b_vec[j]) i++;
            else if(a_vec[i] > b_vec[j]) j++;
        }
        std::cout << count << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
