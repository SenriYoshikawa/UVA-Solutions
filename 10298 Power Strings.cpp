#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string str;
    while (std::cin >> str)
    {
        if (str[0] == '.')
        {
            break;
        }
        int max = 0;
        for (int i = 1; i <= str.size(); ++i)
        {
            if(str.size() % i != 0)
            {
                continue;
            }
            bool flag = true;
            for(int j = i; j < str.size(); j += i)
            {
                if(str.substr(0, i) != str.substr(j, i))
                {
                    flag = false;
                }
            }
            if(flag == true && max < str.size() / i)
            {
                max = str.size() / i;
            }
        }
        std::cout << max << std::endl;
    }
    return 0;
}
