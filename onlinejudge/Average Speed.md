# Average Speed 

[題目連結](https://vjudge.net/problem/UVA-10281)


#### 解題

* 根據題意: 用`scanf`抓值(中間用`:`區隔)
* 我是換成秒再算==>記得用double
* 輸出要小心如果是個位數要在前面補個`0`


#### code

![](https://i.pixiv.cat/img-original/img/2024/03/02/20/36/48/116559486_p1.png)

```cpp
#include<iostream>
#include<vector>
#include<sstream>


using namespace std;


int main()
{
    string s;
    stringstream ss;
    int turn = 0;
    int speed = 0, lastspeed = 0;
    double distance = 0;
    double lasttime = 0;
    double currtime = 0;
    int h, m, second;
    //00:15:01
    while (scanf("%d:%d:%d", &h, &m, &second) != EOF)
    {
        getline(cin, s);
        if (s == "")
        {

            currtime = h * 3600 + m * 60 + second;
            distance += (speed * (currtime - lasttime)) / 3600;
            //cout << s << " " << currtime << " " << lasttime << " " << speed << endl;
            //print time
            if (h < 10)cout << "0";
            cout << h << ":";
            if (m < 10)cout << "0";
            cout << m << ":";
            if (second < 10)cout << "0";
            cout << second;
            printf(" %.2f km\n", distance);
            //cout << speed;
            lasttime = currtime;
        }
        else
        {
            currtime = h * 3600 + m * 60 + second;
            speed = stoi(s);
            if (turn)
            {
                distance += (lastspeed * (currtime - lasttime)) / 3600;
            }
            lasttime = currtime;
            lastspeed = speed;
        }


        turn++;
    }

    return 0;
}
```
