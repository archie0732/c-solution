#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int main()
{

    long long p, q;

    while (cin >> p >> q)
    {
        if (p < 0 && p < 0)break;
        // uva trap
        if (q == 0 && p == 0)
        {
            cout << 0 << endl;
            continue;
        }
        long long ans = 0;
        //sum =  p - q  ==> :
        //sum = -p + q = (p ~ q)
        p--;
        // 先算不含10的部分
        // 共有p層的1~9 ，即1%10+2%10+3%10..... ==> 1+2+3+....+9 = 45(共p組)
        // 有可能第p層不是0結束 ==> 用等差(末項:n) (1+n)*n/2 
        // 再來計算 10為倍數的部分  ==> /10 ，再重複以上
        while (p)
        {
            // (a_n+1)*a_n/2
            ll tem = (p / 10) * 45 + (p % 10 + 1) * (p % 10) / 2;
            ans -= tem;
            p /= 10;
        }
        //
        while (q)
        {
            ll tem = (q / 10) * 45 + (q % 10 + 1) * (q % 10) / 2;
            ans += tem;
            q /= 10;
        }
        cout << ans << endl;
    }
    return 0;

}
