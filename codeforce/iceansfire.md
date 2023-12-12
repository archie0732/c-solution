#  Ice and Fire
[題目連結](https://codeforces.com/problemset/problem/1774/C)  



* 感想: 學再多的技巧也怕題目不懂(有在code裡講一下題目意思)  

* 使用技巧
  >[dp 動態規劃](https://medium.com/%E6%8A%80%E8%A1%93%E7%AD%86%E8%A8%98/%E6%BC%94%E7%AE%97%E6%B3%95%E7%AD%86%E8%A8%98%E7%B3%BB%E5%88%97-dynamic-programming-%E5%8B%95%E6%85%8B%E8%A6%8F%E5%8A%83-de980ca4a2d3)
### 解題
用dp從左至右將答案一個一個存入在一次輸出    

幾個重要的觀念:    
當測值全是1時 可能獲勝的玩家也只有一位(x最大的玩家)    
當測值全是0時 可能獲勝的玩家也只有一位(x為0的玩家)  

**關鍵**  

所以當測值為0001時 輸出會是1 1 1 3  
分開來看:    
1. 0 只有兩人比小，故贏家只有x=1
2. 00比兩次小，故贏家還是只有x=1
3. 000比三次小，故贏家還是只有x=1
4. 0001比三次小後比一次大，因為所有值都大於x=1(除了x=1)故除了x=1其他都有機會贏
(因為前三場會是x=1與未知比決賽，但是比大，x=1一定輸)      
故得1 1 1 3   

還有一個要注意   
當測值是0111時輸出是1 2 2 2  
分開來看:    
1. 0 ==>1 ==>輸出1  
2. 01==>除了x=1不會贏(x=2與x=3都有機會贏)==>輸出2  
3. 011==>除了x=1，x=2不會贏(x=3與x=4都有機會贏)==>輸出 2  
4. 0111==>除了x=1，x=2，x=3不會贏(x=4與x=5都有機會贏)==>輸出 2  
通過兩個範例可以知道當有相同數字排在一起時能贏得數量就會被卡住  
當沒有`連續出現相同值`時有機會贏的人數就是binary string的長度  

### code 

![](https://github.com/archie0732/c-solution/blob/main/picture/ayaka010.jpeg)
```cpp
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

        //存入答案用
        queue<int> ans;
        //兩人一定只有一個人會贏
        ans.push(1);

        int count = 1;
        
        while (s.length() > 0)
        {
            //比較用
            c = s.front();
            //假如發現下一個值相同==>固定答案
            if (c == v.back())
            {
                v.push_back(c);
                s.erase(s.begin());
                ans.push(v.size() - count);
                count++;
            }
            //沒有話或結束重複==>不再固定答案
            else
            {
                v.push_back(c);
                s.erase(s.begin());
                //變回1
                count = 1;
                ans.push(v.size());
            }
        }
        //用queue輸出答案

        while (ans.size() > 0)
        {
            cout << ans.front() << " ";
            ans.pop();
        }

        cout << endl;
    }

    return 0;
}

```
