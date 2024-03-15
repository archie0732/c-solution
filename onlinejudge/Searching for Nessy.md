[題目連結](https://vjudge.net/problem/UVA-11044)


```cpp
#include<iostream>
#include<algorithm>


using namespace std;


int main(){
	
	int t;
	while(cin>>t && t){
		int l,w;
		int l_count = 2,w_count=2;
		while(t--){
			
			cin>>l>>w;
			
			// 邊界可不計(最多2個邊界，又聲納是3格)
			cout<<(l/3)*(w/3)<<endl;
		}
	
	}
	
	return 0;
}
```
