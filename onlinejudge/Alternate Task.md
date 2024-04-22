# Alternate Task


[題目連結](https://vjudge.net/problem/UVA-11728)

#### code 


```cpp
#include<iostream>

using namespace std;



int main(){
	
	int board[1001]={0};
	
	for(int i=1;i<1001;i++){
		for(int j=i;j>0;j--){
			if(i%j==0)board[i]+=j;
		}
	}
	
	int n,Case=1;
	while(cin>>n && n){
		int ans=-1;
		if(n==1){
			ans =1;	 
		}
		for(int i=n-1;i>0&&ans==-1;i--){
			if(board[i]==n){
				ans = i;
				break;
			}
		}
		cout<<"Case "<<Case++<<": "<<ans<<endl;
	}
	
	return 0;
}
```
