#include <iostream>
#include <string>
#include <iomanip>

struct an
{
	double num;
	int size;
};

an get_double(std::string const &s, int n)
{
	int i = 0;
	while (('0' <= s[n + i] && s[n + i] <= '9') || s[n + i] == '.' || s[n + i] == '-')
	{
		i++;
	}
	// std::cout << static_cast<double>(std::atof(s.substr(n, i).c_str())) << std::endl;
	return { static_cast<double>(std::atof(s.substr(n, i).c_str())), i + 1 };
}

an smeech(std::string const &s, int n)
{
	int pn = n;
	double v[3];
	an temp;
	for (int i = 0; i < 3; ++i)
	{
		if (s[n] == ' ')
		{
			n += 1;
			i -= 1;
			continue;
		}
		if (s[n] == '(')
		{
			temp = smeech(s, n + 1);
		}
		else if (('0' <= s[n] && s[n] <= '9') || s[n] == '-' || s[n] == '.')
		{
			temp = get_double(s, n);
		}
		else
		{
            std::cout << s[10000000] << std::endl;
			std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << s[n] << s[n + 1] << s[n + 2] << std::endl;
		}
		n += temp.size;
		v[i] = temp.num;
	}
	// std::cout << "p = " << v[0] << " x = " << v[1] << " y = " << v[2] << " size = " << n-pn+1 << std::endl;
	// std::cout << "ans = " << v[0] * (v[1] + v[2]) + (1 - v[0]) * (v[1] - v[2]) << std::endl;
	return { v[0] * (v[1] + v[2]) + (1 - v[0]) * (v[1] - v[2]), n - pn+2 };
}

int main()
{
	std::string str;
	double ans;
	while (std::getline(std::cin, str))
	{
		// std::cout << str << std::endl;
		if (str.substr(0, 2) == "()")
		{
			break;
		}
		else if (str[0] == '(')
		{
			std::cout << std::fixed << std::setprecision(2) << smeech(str, 1).num << std::endl;
		}
		else
		{
			std::cout << std::fixed << std::setprecision(2) << std::atof(str.c_str()) << std::endl;
		}
	}
	return 0;
}
