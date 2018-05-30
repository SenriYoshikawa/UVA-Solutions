#include <iostream>
#include <string>
#include <bitset>

int main()
{
	int p;
	std::cin >> p;
	std::cin.ignore();

	for (p; p > 0; --p)
	{
		bool ans = false;
		std::bitset<26> v(0);
		std::bitset<26> nv(0);
		std::string str;
		std::cin >> str;
		for(int i = 0; i < str.size() && str[i] != '\n'; ++i)
		{
			if (str[i] == '(')
			{
				v = 0;
				nv = 0;
			}
			else if (str[i] == ')')
			{
				if ((v & nv) == 0)
				{
					ans = true;
				}
			}
			else if (str[i] == '~')
			{
				nv.set(str[++i] - 'a');
			}
			else if ('a' <= str[i] && str[i] <= 'z')
			{
				v.set(str[i] - 'a');
			}
		}
		if (ans == true)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
