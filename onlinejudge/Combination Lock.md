# Combination Lock 



[題目連結](https://vjudge.net/problem/UVA-10550#author=0)




#### 解題


* 順時針轉扭==>數字是逆時針轉動


```
     00
  D      A
30        10
  C      B
     20
```

* 以00/40==>10舉例

>1. 順時針轉動 ==> -10度
>2. 逆時針轉動 ==>  10度
>
>又-10度可以變為40-10=30度

* 取mod40為了0度與40度是同個刻度 ==> 避免溢值


```cpp
#include<iostream>
#include<vector>



using namespace std;


int main(){

int begin,f1,f2,f3;


int d = 9;
// 轉順時針，數字是走逆時針
while(cin>>begin>>f1>>f2>>f3 && (begin+f1+f2+f3)){
	
	int ans = 720;
	ans+= ((begin-f1)+40)%40*d;
	ans+= 360;
	ans+=((f2-f1)+40)%40*d;
	ans+=((f2-f3)+40)%40*d;
	cout<<ans<<endl;
}


return 0;
}
```
