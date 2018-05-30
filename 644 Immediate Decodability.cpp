#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> sv;
    std::string a;
    bool flag = true;
    int p = 0;
    while (std::cin >> a)
    {
        if (a[0] == '9')
        {
            p += 1;
            if (flag == true)
            {
                std::cout << "Set " << p << " is immediately decodable" << std::endl;
            }
            else
            {
                std::cout << "Set " << p << " is not immediately decodable" << std::endl;
            }
            flag = true;
            sv.clear();
        }
        else
        {
            if (flag == false)
            {
                continue;
            }
            for (std::string &s : sv)
            {
                bool temp = false;
                for (int i = 0; (s[i] == '0' || s[i] == '1') && (a[i] == '0' || a[i] == '1'); ++i)
                {
                    if (s[i] != a[i])
                    {
                        temp = true;
                        break;
                    }
                }
                flag = temp;
                if(flag == false)
                {
                    break;
                }
            }
            sv.emplace_back(a);
        }
    }
}

/*
即時符号かどうかを判定する問題．c++で実装した．
これまでに現れたシンボルと新たなシンボルが先頭から見比べて
どちらかの符号が完全に含まれるケースがあるかどうかを調べる．
*/
