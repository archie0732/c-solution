# You can say 11
[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870)
### 題目
Your job is, given a positive number N, determine if it is a multiple of eleven.(until input 0)

* sample input
```
112233  
30800  
2937  
323455693  
5038297  
112234  
0  
```
* sample output
```
112233 is a multiple of 11.
30800 is a multiple of 11.
2937 is a multiple of 11.
323455693 is a multiple of 11.
5038297 is a multiple of 11.
112234 is not a multiple of 11.
```

### 題目翻譯

找出是輸入否為11的倍數(直到輸入為0)

#### 解題

是不是覺得只要對輸入取`11的餘數`為0就行了?


$`\textcolor{blue}{會超時}`$  
$`\textcolor{green}{會超時}`$    
$`\textcolor{red}{會超時}`$    

怎麼辦呢?

只要知道這個原理就能秒殺了  
**(偶數位置之合-奇數位置之合)除11取餘數**(從最左邊來看)
>如果是0==>是  
>反之==>否

證明
>以112233為例  
>偶數位置1+2+3=6   
>奇數位置1+2+3=6
>(6-6)%11=0&11=0

>再以30800為例  
>偶數位置3+8+0=11  
>奇數位置0+0+0=0  
>(11-0)%11=0  

>112234
>偶數位置1+2+3=6  
>奇數位置1+2+4=7  
>(6-7)%11=-1(不是)

利用這個技巧，就可以避免對一個很大的數字進行除法，節省時間  
#### code
```cpp
#include <iostream>
#include <string.h>

using namespace std;


/*
    題目:You can say 11
    題目來源:online judge 
    題目連結:https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870
    解題語言:c++
    解題者:神里綾華的狗
    解題連結:
*/
int main()
{
    string s;
    while (cin >> s)
    {
        if (s == "0")
            break;
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //字串轉化數字
            int n = s[i] - '0';
            //偶數位置分到這
            if (i % 2 == 0)
                a += n;
            //奇數位置分到這
            else
                b += n;
        }
        if ((a - b) % 11 == 0)
            cout << s << " is a multiple of 11." << endl;
        else
            cout << s << " is not a multiple of 11." << endl;
    }

    return 0;
}
```
