#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double l, w, h, theta;
    while(std::cin >> l >> w >> h >> theta)
    {
        theta = theta / 180 * M_PI;
        double ans;
        if(theta < std::atan2(h, l))
        {
            ans = (h - l*std::tan(theta)/2)*l*w;
        }
        else
        {
            ans = h*h*tan(M_PI /2 - theta)*w/2;
        }
        std::cout << std::fixed << std::setprecision(3) << ans << " mL" << std::endl;
    }
    return 0;
}

/*
上面がない直方体を液体で満たし、theta度ロールした時の残りの液体の量を求める問題。
thetaが横から見たときの長方形の対角線を超えるか否かで場合分けをして、
超えていないときは減った分を三角柱の体積として、超えたときは残りを三角柱の体積として
それぞれ求めることができる。
*/
