# Constructing a Number
Manipulating numbers is at the core of a programmer's job. To test how well you know their properties, you are asked to solve the following problem.

You are given  non-negative integers , , ..., . You want to know whether it's possible to construct a new integer using all the digits of these numbers such that it would be divisible by . You can reorder the digits as you want. The resulting number can contain leading zeros.

For example, consider the numbers  from which you have to construct a new integer as described above. Numerous arrangements of digits are possible; but we have illustrated one below.


![](https://github.com/archie0732/c-solution/blob/main/picture/1514370322-1398c77ec5-number_cons1.png)

Complete the function canConstruct which takes an integer array as input and return "Yes" or "No" based on whether or not the required integer can be formed.

Input Format

The first line contains a single integer  denoting the number of queries. The following lines describe the queries.

Each query is described in two lines. The first of these lines contains a single integer . The second contains  space-separated integers a1,a2 ,a3 ...,an .

Constraints

Subtasks

For 33.33% of the total score:

Output Format

For each query, print a single line containing "Yes" if it's possible to construct such integer and "No" otherwise.
***
### **sample**  
input:
```
3  
1  
9  
3  
40 50 90  
2  
1 4
```  
output:  
```
Yes
Yes
No
```
***
## note 
因為是除以3==>有以下規則:  
**整數拆成`個位數` `相加之和`能夠被三整除==>這個整數能被三整除**    


ex:  
5472 ==> 5、4、7、2 ==>`相加`為18能被整除


所以只要將`本身非3的倍數之值`輸入值給**分類**與**計算次數**後相加在去除3即可

例題範例
50 40 90 ==>5(1次)、4(1次)、9(一次、但本身就**會被三整除所以不加入計算**) 、0(不加入計算)  
==> 5+4==>9%3==0 :Yes;
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v0;
        map<int, int> mymap;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            // 拆分數字
            while (v[i] > 0)
            {
                int tem;
                tem = v[i] % 10;
                if (tem % 3 == 0)
                {
                    v[i] = v[i] / 10;
                    continue;
                }
                else if (mymap[tem] == 0)
                    v0.push_back(tem);

                mymap[tem]++;
                v[i] = v[i] / 10;
            }
        }
        long ans = 0;
        for (int i = 0; i < v0.size(); i++)
        {
            ans = ans + v0[i] * mymap[v0[i]];
        }
        if (ans % 3 == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
```
