#include<iostream>
#include<cmath>
#define PI 2*acos(0.0)

//https://vjudge.net/problem/UVA-10678
using namespace std;


int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int p, r;
        cin >> p >> r;

        //橢圓形面積 短軸半徑 * 長軸半徑 * PI
        double c = p / 2.0;
        // 長軸
        double a = r / 2.0;
        // 短軸
        double short_edge = sqrt(a * a - c * c);
        //cout << short_edge << endl;

        double ans = short_edge * a * PI;

        printf("%.3f\n", ans);

    }


    return 0;
}
