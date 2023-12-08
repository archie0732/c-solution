# In love

Initially, you have an empty multiset of segments. You need to process q  
 operations of two types:  

* +lr  
 — Add the segment (l,r)

 to the multiset,  
* −lr  
 — Remove exactly one segment (l,r)    
 from the multiset.

It is guaranteed that this segment exists in the multiset.  
After each operation, you need to determine if there exists a pair of segments in the multiset that do not intersect. A pair of segments (l,r)  and (a,b)    
 do not intersect if there does not exist a point x such that l≤x≤r and a≤x≤b  .

## 題目翻譯
輸入t次(執行t次)    
當輸入+lr及 ==>增加一組集合進入空間[l,r]      
當輸入-lr及 ==>刪除一組在空間中的集合[l,r] (**保證存在於空間**)  

試問是否能找到兩組集合**不相交**  
另如[1,2]與[3,4]不相交      
但[1,2]與[2,2]相交(於2)    

P.S L<=R !!!    

##  解題
因為一些原因   
放在code的註解裡    

### code
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#define nmsl INT_MAX

using namespace std;

/*
//* 以防又有人覺得在抄，以後都會附上並且會鑽寫解題過程
    題目:In Love from
    解題日期:2023/12/08
    解題者:神里綾華的狗(dasabi7414)
    題目連結:https://codeforces.com/contest/1883/my
    解題連結(請看完後再下定論):

//* 備註:以後有任何疑問請直接找我，在背後講好像不是很光明的選擇
*/

// 建立一個set ，可以在值進入時就排序
multiset<int, less<int>> L, R;

// 解題
/*
    貪心演算法
    因為l恆<=r ==>所以只要在R的最小值<L的最大值時表示一定能找到至少一組不相交的兩條線
    舉例 當 R(min)=2 < L(max)=3 時
    必至少有一組R=(1,2)或(2,2) ; L=(3,3)或(3,>3)
*/

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        char c;
        int r, l;
        cin >> c;
        cin >> l >> r;
        // 當使用這輸入 '+'>>l>>r 時插入multiset(因為有less<int>所以會排序==>由小到大)
        if (c == '+')
        {
            L.insert(l);
            R.insert(r);
        }
        // 當使用者輸入 '-'>>l>>r 時找出l,r之位置並刪除(使用find)
        else if (c == '-')
        {

            L.erase(L.find(l));
            R.erase(R.find(r));
        }

        // 當只有一組時(l,r各一個)==>輸出no
        if (L.size() <= 1)
        {
            cout << "NO" << endl;
        }
        // 使用指標(因為end只的是空間故要再少1)找到位置並己較其內的值
        else if (*R.begin() < *(--L.end()))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        /*
        我連測試時用的輸出都留下來....
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
        */
    }
    return 0;
}
// 那時候說上課要講題目，結果也沒講....
```
