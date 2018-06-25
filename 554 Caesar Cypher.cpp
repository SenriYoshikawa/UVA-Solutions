#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char nextChar(char c)
{
    if(c == ' ')
    {
        return 'A';
    } 
    else if(c == 'Z')
    {
        return ' ';
    }
    else if('A' <= c && c <= 'Z')
    {
        return ((c - 'A') + 1) % 26 + 'A';
    }
    else
    {
        return c;
    }
}

int main()
{
    std::string s;
    std::vector<std::string> sv;
    sv.reserve(20);
    while(s != "#")
    {
        std::cin >> s;
        sv.emplace_back(s);
    }
    sv.erase(sv.end());

    std::cin.ignore();
    std::getline(std::cin, s);
    if (s[s.size()-1] == '\n') s.erase(s.size()-1);
    if (s[s.size()-1] == '\r') s.erase(s.size()-1);
    std::string str = "";
    int max = 0, diff;

    for(int i = 0; i < 27; ++i)
    {
        for(int j = 0; j < s.size(); ++j)
        {
            s[j] = nextChar(s[j]);
        }
        
        int count = 0;
        for(auto const& ele : sv)
        {
            int pos = s.find(ele);
            while(pos != -1)
            {
                count++;
                pos = s.find(ele, pos+1);
            }
        }
        if(max < count)
        {
            max = count;
            diff = i;
            str = s;
        }
    }

    for(int i = str.size()-1; i > 0 && !('A' <= str[i] && str[i] <= 'Z'); --i)
    {
        str.erase(i);
    }

    for(int i = 60; i < str.size(); i += 60)
    {
        for(int j = i+1; j > i-59 && j < s.size(); --j)
        {
            if(str[j] == ' ')
            {
                str[j] = '\n';
                i = j;
                break;
            }
        }
    }

    std::cout << str << std::endl;

    return 0;
}