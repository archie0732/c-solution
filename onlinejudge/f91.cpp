#include<iostream>
#define ll long long

//https://vjudge.net/problem/UVA-10696

using namespace std;


ll f91(int N)
{

    if (N >= 101)return N - 10;
    else
    {
        return f91(f91(N + 11));
    }

}

int main()
{

    ll N, contain_N;
    while (cin >> N && N)
    {
        contain_N = N;
        ll ans = N >= 101 ? N - 10 : 91;
        cout << "f91(" << contain_N << ") = " << ans << endl;

    }

    return 0;
}
