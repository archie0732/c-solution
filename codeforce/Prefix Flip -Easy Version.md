# Prefix Flip -Easy Version


#### code 
```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        vector<int> ans;
        cin >> a >> b;

        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                ans.push_back(i);
                if (a[0] == '0')
                    a[0] = '1';
                else
                    a[0] = '0';
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (b[i] != a[0])
            {
                ans.push_back(i + 1);
                if (a[0] == '0')
                    a[0] = '1';
                else
                    a[0] = '0';
            }
        }
        cout << ans.size();
        for (int i = 0; i < ans.size(); i++)
            cout << " " << ans[i];
        cout << endl;
    }

    return 0;
}
```
