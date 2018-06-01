#include <iostream>
#include <cmath>

int main()
{
    int w, l, c1, c2;
    std::cin >> w >> l >> c1 >> c2;
    while(w != 0 || l != 0 || c1 != 0 || c2 != 0)
    {
        if(w < c1*2 || l < c1 *2 || w < c2*2 || l < c2*2)
        {
            std::cout << "N" << std::endl;
        }
        else if(std::sqrt(std::pow(l-(c1+c2), 2) + std::pow(w - (c1+c2), 2)) >= c1+c2)
        {
            std::cout << "S" << std::endl;
        }
        else
        {
            std::cout << "N" << std::endl;
        }
        std::cin >> w >> l >> c1 >> c2;
    }
    return 0;
}

/*
与えられた長方形の中に与えられた二つの円が入るかを判定する問題。ｃ＋＋で実装した。
そもそも1つの円が長方形の中に入るかを判定し、入るのであれば2つの円が入るかを判定する。
縦横それぞれから2つの半径を引いた残りが作る対角線が、2つの円の半径の和より大きければ2つの円を入れることができる。
*/