#include <iostream>
#include <vector>
#include <cmath>
#include<map>
//https://vjudge.net/problem/UVA-11001




/*
        記得v與v0一定要轉double 不然會死得很慘
*/
using namespace std;

int main()
{
    double v, v0;
    while (cin >> v >> v0 && v && v0)
    {
        double max = 0;
        int ans = 0;
        map<double, int> lengths;


        for (int i = 1; i < v; ++i)
        {
            if (v / i > v0)
            {
                double change = 0.3 * sqrt(v / i - v0) * i;
                change = floor(change * 100000) / 100000;
                lengths[change]++;
                if (change > max)
                {
                    max = change;
                    ans = i;
                }
            }
        }


        if (lengths.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            int flag = 0;
            if (lengths[max] > 1)
            {
                cout << "0" << endl;
            }
            else cout << ans << endl;
        }
    }
    return 0;
}
