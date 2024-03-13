#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Build
{
    int left;
    int right;
    int hight;
};

int main()
{
    Build b[10000];
    int left, right, hight, turn = 0;
    int a[10000];
    int R = 0;
    while (cin >> b[turn].left >> b[turn].hight >> b[turn].right)
    {
        for (int i = b[turn].left; i < b[turn].right; i++)
        {
            a[i] = max(a[i], b[turn].hight);
        }
        R = max(R, b[turn].right);
        turn++;
    }

    int L = b[0].left;

    for (int i = L; i <= R; i++)
    {
        if (a[i] != a[i - 1])
        {
            cout << i << " " << a[i];

            if (i != R)
                cout << " ";
        }
    }
    cout << endl;
}
