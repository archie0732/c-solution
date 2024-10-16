#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        vector<int> index;
        index.push_back(1);

        int i = -1, j = -1, k = -1, flag = 0;

        for (int cur = 2; cur <= n; cur++)
        {

            if (index.size() >= 2 && arr[index.back()] > arr[cur] && arr[index[index.size() - 2]] > arr[cur])
            {
                k = cur;
                j = index.back();
                i = index[index.size() - 2];
                flag = 1;
                break;
            }

            if (arr[index.back()] <= arr[cur])
            {
                index.push_back(cur);
            }
            else if (!index.empty())
            {
                index.pop_back();
                index.push_back(cur);
            }
        }

        if (flag)
        {
            cout << "yes " << i << " " << j << " " << k << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
