# Least Product

# Least Product

先祝各位，新年快樂

這是跨年前，來寫一些簡單一點


[題目連結](https://codeforces.com/problemset/problem/1917/A)




#### 解題

因為是乘法，有兩個性質

1. 任何數字乘 `0` 答案都是 0
2. 乘以`基數的負數`答案是負數

又因為只能在![](https://ithelp.ithome.com.tw/upload/images/20231231/20164500yZCBp6edyi.png) ~ 0 之間

幾種情況 

1. 如果乘積**大於零** ==> 乘出來的值大於零，最小值只能為0==>乘0
2. 如果乘積**小於零** ==> 乘出來的值小於零，即為最小值
3. 如果只有一個值 ==> 答案為 1 或 0，在依照正負去判斷
4. 如果是零　　　 ==> 答案只能是 1 ，因為怎麼乘答案都是 0 



#### code 

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        bool flag = false;
        vector<int> v(n);
        vector<int> check;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] < 0)
            {
                check.push_back(i);
            }
            else if (v[i] == 0)
                flag = true;
        }
        if (flag == true)
            cout << 0 << endl;
        else if (check.size() % 2 == 1 && check.size() != 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl
                 << "1 " << 0 << endl;
        }
    }
    return 0;
}
```


