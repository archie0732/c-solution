# Cheapest Base 

[題目連結](https://vjudge.net/problem/UVA-11005)



* 十進位轉其他進位的方法==>短除法
* 記得n要用備檔來做短除法

```cpp
#include<bits/stdc++.h>

#define ll long long
using namespace std;

// 11 ==> 1 5||11 2|| 110 0|| 
int main(){

	int t,turn=1;
	cin>>t;
	
	while(t--){
		if(turn>1)cout<<endl;
		map<int,int> mp;
		
		for(int i=0;i<36;i++){
			cin>>mp[i];
		}
		
		int n;
		cin>>n;
		
		cout<<"Case "<<turn++<<":"<<endl;
		while(n--){
			ll a,mn=100000000;
			cin>>a;
			
			map<int,int> use;
			cout<<"Cheapest base(s) for number "<<a<<":";
			for(int i=2;i<=36;i++){
				ll tem = a,cost=0;
				
				while(tem>0){
					cost += mp[tem%i];
					tem/=i;
				}
				
				mn = min(mn,cost);
				use[i]= cost;
			}
			
			for(auto it : use){
				if(it.second==mn){
					cout<<" "<<it.first;
				}
			}
			cout<<endl;
		}
	}

}
```
