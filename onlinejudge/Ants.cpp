#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int le, num;
        cin >> le >> num;
        vector<int> ants(num);
        for (int i = 0;i < num;i++)
        {
            cin >> ants[i];
        }
        int max_time = 0, min_time = 0;

        for (int i = 0;i < num;i++)
        {
            min_time = max(min(ants[i], le - ants[i]), min_time);
            max_time = max(max(ants[i], le - ants[i]), max_time);
        }

        cout << min_time << " " << max_time << endl;
    }

    return 0;
}
