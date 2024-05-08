# cola


[題目連結](https://vjudge.net/problem/UVA-11150)


#### 解題

* n/3 ==> 可以兌換的數輛
* n%3 ==> 剩下沒換的數量

* 所以只要`n+n'/3+n''/3...`直到`n<3`時就是答案
* 然後再算借1瓶與借2瓶的情況==>如果算出來**最後的n小於借的數量則不成立**



#### code 





```cpp
#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

long slove(int n, int ans, int check)
{
  if (n <= 2)
  {
    if (n < check)
    {
      return -1;
    }
    return ans;
  }
  ans += n / 3;

  return slove(n / 3 + n % 3, ans, check);
}

int main(int argc, char const* argv[])
{
  int n;
  while (cin >> n)
  {
    int ans1, ans2, ans3;

    ans1 = slove(n, n, 0);
    ans2 = slove(n + 1, n, 1);
    ans3 = slove(n + 2, n, 2);

    ans1 = max(ans1, ans2);
    ans1 = max(ans1, ans3);

    cout << ans1 << endl;

  }

  return 0;
}
```


#### 5/8 更新

```cpp
#include<bits/stdc++.h>

using namespace std;

int slove(int num,int add){

    int res = num;
    
    num+=add;

    while(num >= 3){
        int left = num%3;

        res+=num / 3;

        num = num / 3 + left;
    }

    if(num<add){
        return -1;
    }

    return res;
}


int main(){

    int n;

    while(cin>>n){
        
        int ans = slove(n,0);

        ans = ans>=slove(n,1)? ans : slove(n,1)>=slove(n,2)?slove(n,1):slove(n,2);

        cout<<ans<<endl;
    }

    return 0;
}
```
