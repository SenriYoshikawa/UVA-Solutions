#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <iomanip>

int main()
{
    int problem;
    std::cin >> problem;
    for(problem; problem > 0; --problem)
    {
        std::map<char, int> dict;
        int n_dict;
        std::cin >> n_dict;
        for(n_dict; n_dict > 0; --n_dict)
        {
            char c;
            int cost;
            std::cin >> c >> cost;
            dict.insert(std::make_pair(c, cost));
        }

        int n_str = 0, total_cost = 0;
        std::cin >> n_str;
        std::cin.ignore();
        for(n_str; n_str > 0; --n_str)
        {
            std::string str;
            std::getline(std::cin, str);
            const char* char_str = str.c_str();
            for(std::size_t i = 0; i < str.length(); ++i)
            {
                auto cost_it = dict.find(char_str[i]);
                total_cost += cost_it == dict.end() ? 0 : cost_it->second;
            }
        }
        std::cout << total_cost / 100 << "." << std::setw(2) << std::setfill('0') << total_cost % 100 << "$" << std::endl;
    }
}
