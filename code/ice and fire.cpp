#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
//* 題目:ice and fire
    題目來源:codeforce
    題目連結:https://codeforces.com/problemset/problem/1774/C
    解題者:神里綾華的狗
    解題語言:C++
    解題連結:

    使用技巧:dp

//* P.S. 首先，要先看得懂題目，其次要找到規律，最後會用dp
*/

/*
//*    題目意思

        0==>兩人比小(小的晉級，大的滾)
        1==>兩人比大(大的晉級，小的滾)


    比賽人員與出賽表
    假如有三人(參賽表)，選手==> a(x=1),b(x=2),c(x=3)
         |
        ------
       |      |
     ----     |
    |    |    |
    a    b    c  (沒規定選手要怎麼排，也能夠bc a、ca b)

    分出勝負:0==>分數較低win ; 1==>分數較高win

    範例(用測值 4 001舉例)
    當有測值001(先看最左邊0)
    選手:a(x=1),b(x=2)
    此時:
        |
     --------  (0，比小)
    |        |
    |        |
    a(x=1)   b(x=2)

    不管怎麼換邊只有a獲勝。故輸出1(只有一個人有機會贏)


    再來看001的00(比賽依序是:比小、比小)
    因為是3人[ax(x=1),b(x=2),c(x=3)]，所以參賽表會變成這樣

            |
            | 0
         -------
        |       |
        | 0     |
     ------     |
    |      |    |
    |      |    |
    a      b     c

    a與b比誰較小(最左邊0)，贏的再去與c比小(中間的0)

    你會發現不管怎麼換a、b、c的位置都只有x=1贏

    故有機會獲勝的人只有一人(x=1)==>輸出1



    最後，看001 (比賽依序是:比小、比小、比大)
    因為參賽人數是4人a(x=1),b(x=2),c(x=3),d(x=4)
    參賽表如下:

            | 1
         ---------
        |         |
        | 0       |
      ------      |
     | 0    |     |
    ---     |     |
   |   |    |     |
   a   b    c     d

    最後不管你怎麼換位置==>a(x=1)都不可能贏
    所以以鳩會贏的為b、c、d共三人輸出 ==> 3

*/

/*

    ok，終於到解題了
    因為怕太長所以放在我的github
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        char c = s.front();
        vector<char> v;

        v.push_back(c);
        s.erase(s.begin());

        queue<int> ans;
        ans.push(1);

        int count = 1;
        while (s.length() > 0)
        {
            c = s.front();

            if (c == v.back())
            {
                v.push_back(c);
                s.erase(s.begin());
                ans.push(v.size() - count);
                count++;
            }
            else
            {
                v.push_back(c);
                s.erase(s.begin());
                count = 1;
                ans.push(v.size());
            }
        }
        while (ans.size() > 0)
        {
            cout << ans.front() << " ";
            ans.pop();
        }

        cout << endl;
    }

    return 0;
}
