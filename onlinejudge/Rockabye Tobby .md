# Rockabye Tobby 


[題目連結](https://vjudge.net/problem/uva-13190)



```cpp

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>



using namespace std;


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, string>>medic(n);
        vector<int>day(n, 0);


        // 藥品名稱 天數
        // day 紀錄已經使用天數
        for (int i = 0;i < n;i++)
        {
            int d;
            string name;
            cin >> name >> d;
            medic[i] = { d,name };
            day[i] = d;
        }

        while (m--)
        {
            pair<int, string> ans = { medic[0] };
            pair<int, int> now_day = { day[0],0 };
            for (int i = 1;i < n;i++)
            {
                if (now_day.first > day[i])
                {
                    now_day.first = day[i];
                    now_day.second = i;
                    ans = { medic[i] };
                }

            }



            cout << day[now_day.second] << " " << ans.second << endl;
            day[now_day.second] += medic[now_day.second].first;
        }





    }

    return 0;
}


```
