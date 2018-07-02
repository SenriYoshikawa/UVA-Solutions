// TLE
#include <cstdio>
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <string.h>
#include <algorithm>

std::array<int, 64> data;
std::array<std::array<std::vector<int>, 32>, 32> memo;

std::pair<std::array<int, 64>, int> split(const std::string &input)
{
    const char delimiter = ' ';
    std::istringstream stream(input);

    std::string field;
    std::array<int, 64> result;
    result[0] = 1;
    int i = 1;
    while (std::getline(stream, field, delimiter))
    {
        if (field.c_str()[0] == '+')
        {
            result[i++] = 1;
        }
        else if (field.c_str()[0] == '-')
        {
            result[i++] = -1;
        }
        else if (field.c_str() == "\n")
        {
            break;
        }
        else
        {
            result[i++] = std::stoi(field.c_str());
        }
    }
    return std::move(std::make_pair(result, i));
}

std::vector<int> &bracket(int l, int r)
{
    std::vector<int> &rtn_vec = memo[l / 2][r / 2];
    if (rtn_vec.size() != 0)
    {
        return rtn_vec;
    }

    if (r - l == 2)
    {
        rtn_vec.emplace_back(data[l + 1]);
    }
    else
    {
        for (int m = l + 2; m < r; m += 2)
        {
            std::vector<int> &l_vec = bracket(l, m);
            std::vector<int> &r_vec = bracket(m, r);
            for (int i = 0; i < l_vec.size(); ++i)
            {
                for (int j = 0; j < r_vec.size(); ++j)
                {
                    rtn_vec.emplace_back(l_vec[i] + data[m] * r_vec[j]);
                }
            }
        }
    }
    std::sort(rtn_vec.begin(), rtn_vec.end());
    rtn_vec.erase(std::unique(rtn_vec.begin(), rtn_vec.end()), rtn_vec.end());
    return rtn_vec;
}

int main()
{
    std::string str;
    while (std::getline(std::cin, str) && str != "")
    {
        for (int i = 0; i < 32; ++i)
        {
            for (int j = 0; j < 32; ++j)
            {
                memo[i][j] = std::vector<int>(0);
                memo[i][j].reserve(1000);
            }
        }
        auto datan = std::move(split(str));
        data = datan.first;
        std::vector<int> &ans_vec = bracket(0, datan.second);

        printf("%lu\n", ans_vec.size());
    }
    return 0;
}