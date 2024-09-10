#include <iostream>

using namespace std;

int main()
{
    int a[5] = {100, 100, 30, 60, 70};

    int ans = 0;
    for (int it : a)
    {
        ans += it;
    }

    cout << ans / 5 << endl;

    return 0;
}