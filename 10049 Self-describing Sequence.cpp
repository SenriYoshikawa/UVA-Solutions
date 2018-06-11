#include <iostream>
#include <vector>

int main()
{
    std::vector<int> data(1000000, 2000000001);
    
    data[1] = 1;
    data[2] = 2;
    data[3] = 4;
    data[4] = 6;
    data[5] = 9;


    int k = 2;
    for(uint64_t i = 2, j = 2; i < 2000000001; ++j)
    {
        data[j] = i;
        for(k; data[k] <= j; ++k)
        {}
        i+= k-1;
        
    }
    
    uint64_t n;
    std::cin >> n;
    while(n != 0)
    {
        int j;
        for(j = 1; data[j] <= n; ++j)
        {}
        std::cout << j-1 << std::endl;

        std::cin >> n;
    }
    
   return 0;
}

