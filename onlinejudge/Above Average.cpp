#include<iostream>
#include<vector>
#include<cmath>
#define ll long long

using namespace std;


int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n;
        cin >> n;
        vector<int> score(n);
        ll sum = 0;

        for (int i = 0;i < n;i++)
        {
            cin >> score[i];
            sum += score[i];
        }

        int av = sum / n;
        int pass_p = 0;
        for (int i = 0;i < n;i++)
        {

            if (score[i] > av)
            {
                pass_p += 1;
            }
        }
        double pass_rant = (double)pass_p / (double)n * 100.00;

        printf("%.3f", pass_rant);
        cout << "%" << endl;

    }


    return 0;
}
