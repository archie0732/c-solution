#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{

    string s;
    int turn = 1;

    while (cin >> s)
    {

        int n;
        cin >> n;
        int begin, end;
        cout << "Case " << turn << ":" << endl;
        turn++;
        while (n--)
        {
            cin >> begin >> end;
            if (begin > end)swap(begin, end);

            string check = s.substr(begin, end - begin + 1);
            string check_2 = string(end - begin + 1, check[0]);

            if (check != check_2)cout << "No" << endl;
            else cout << "Yes" << endl;

        }


    }


    return 0;
}
