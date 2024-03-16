# Counting Chaos

[題目連結](https://vjudge.net/problem/UVA-11309)




#### code

![](https://i.pixiv.cat/116494272.png)

```cpp

#include<iostream>
#include<stdio.h>


using namespace std;

int main()
{

    int t;
    while (cin >> t)
    {

        while (t--)
        {

            int h, m;
            scanf("%d:%d", &h, &m);
            int now_time = h * 60 + m;

            while (true)
            {
                now_time++;
                if (now_time >= 1440)
                {
                    now_time = 0;

                }
                h = now_time / 60;
                m = now_time % 60;

                if (h == 0 && (m < 10 || m / 10 == m % 10))break;
                if (h < 10 && (h % 10 == m % 10) && (m % 10 != 0))break;
                if (h >= 10 && h / 10 == m % 10 && h % 10 == m / 10)break;

                //cout << h << ":" << m << endl;
            }

            if (h < 10)cout << "0";
            cout << h << ":";
            if (m < 10)cout << "0";
            cout << m << endl;
        }

    }


    return 0;
}
```
