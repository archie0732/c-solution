# Do your own homework

[題目連結](https://vjudge.net/problem/UVA-11917)

* 水題

#### code 


```cpp
#include<iostream>
#include<map>


using namespace std;


int main(){
	
	int t,turn=1;
	cin>>t;
	
	while(t--){
	
		int n,usetime;
		string s;
		cin>>n;
		map<string,int> mp;
		for(int i=0;i<n;i++){
			cin>>s>>usetime;
			mp[s]=usetime;
		}
		int deadline;
		cin>>deadline>>s;
		cout<<"Case "<<turn++<<": ";
		if(mp.count(s)){
			if(mp[s]<=deadline)cout<<"Yesss"<<endl;
			else if(mp[s]<=deadline+5)cout<<"Late"<<endl;
			else cout<<"Do your own homework!"<<endl;
		}
		else{
			cout<<"Do your own homework!"<<endl;
		}
	
	}

	return 0;
}
```
