#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

void slove()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    stack<int> index;
    index.push(1);

    int i = -1, j = -1, flag = 0, last = 0;
    int valI, valJ, valK;

    for (int k = 2; k <= n; k++)
    {
        if (arr[index.top()] > arr[k] && index.size() >= 2)
        {
            valJ = arr[index.top()];
            j = index.top();
            index.pop();
            if (arr[index.top()] > arr[k])
            {
                flag = 1;
                valI = arr[index.top()];
                i = index.top();
                valK = arr[k];
                last = k;
                index.pop();
            }
            else
            {
                index.push(k);
            }
        }
        else
        {
            index.push(k);
        }

        if (flag == 1)
            break;
    }

    if (flag == 1)
    {
        cout << "yes " << i << " " << j << " " << last << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
}