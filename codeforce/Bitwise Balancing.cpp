#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> b >> c >> d;
        a = ((d | b) - (d & c));
        if (((a | b) - (a & c)) == d)
            cout << a << endl;
        else
            cout << "-1" << endl;
    }
}