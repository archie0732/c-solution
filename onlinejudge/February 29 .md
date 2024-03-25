# February 29 

[題目連結](https://vjudge.net/problem/Uva-12439)




* a 到 b 年間有幾個閏年

* 0-b年的潤年數 `-` 0-a年的閏年數


```cpp
#include<bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> date;
    date["January"] = 1;
    date["February"] = 1;

    string sl;
    int t, turn = 1;
    cin >> t;
    getline(cin, sl);
    while (t--)
    {
        string s, m, m2;
        int day, day2, year, year2, ans = 0;
        getline(cin, s);

        stringstream ss(s);
        ss >> m >> day >> sl >> year;
        ss.clear();
        getline(cin, s);


        ss.str(s);
        ss >> m2 >> day2 >> sl >> year2;

        //cout << m2 << " " << day2 << " " << year2 << endl;

        if ((m[0] == 'J' && m[1] == 'a') || m[0] == 'F')
        {
            year--;
        }
        if ((m2[0] == 'J' && m2[1] == 'a') || (m2[0] == 'F' && day2 != 29))
        {
            year2--;
        }


        //cout << year << " " << year2 << endl;


        int t1 = year / 4 - year / 100 + year / 400;
        int t2 = year2 / 4 - year2 / 100 + year2 / 400;


        cout << "Case " << turn++ << ": " << t2 - t1 << endl;

    }


    return 0;
}
```
