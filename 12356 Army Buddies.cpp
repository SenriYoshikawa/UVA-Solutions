#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>

int main()
{
    int s, b;
    while (std::cin >> s >> b)
    {
        if (s == 0 && b == 0)
        {
            break;
        }

        std::vector<int> left(s + 2);
        std::vector<int> right(s + 2);

        for (std::size_t i = 0; i < right.size(); ++i)
        {
            right.at(i) = i + 1;
            left.at(i) = i - 1;
        }

        for (int i = 0; i < b; ++i)
        {
            int l, r;
            std::cin >> l >> r;
            left.at(r+1) = left.at(right.at(r)) = left.at(l);
            right.at(l-1) = right.at(left.at(l)) = right.at(r);

            if(left.at(r+1) < 1) std::cout <<  "* ";
            else std::cout << left.at(r+1) << " ";
            if(right.at(l-1) > s) std::cout << "*\n";
            else std::cout << right.at(l-1)  << "\n";
        }
        std::cout << "-" << "\n";
    }

    return 0;
}
