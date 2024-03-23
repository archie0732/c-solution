# Bangla Numbers 

[題目連結]()

* 都要要空4格(用printf)
* 注意空格(數字與字母間的空格)
* 只有 0 時要輸出

#### code



```cpp

#include<bits/stdc++.h>
#define ll long long
using namespace std;



void print_ans(ll n){

	if(n/10000000){
		print_ans(n/10000000);
		cout<<" kuti";
		n%=10000000;
	}
	
	if(n/100000){
		print_ans(n/100000);
		cout<<" lakh";
		n%=100000;
	}
	
	if(n/1000){
		print_ans(n/1000);
		cout<<" hajar";
		n%=1000;
	}
	
	if(n/100){
		print_ans(n/100);
		cout<<" shata";
		n%=100;
	}
	
	if(n!=0)cout<<" "<<n;

}


int main(){

	ll s,turn=1;
	
	while(cin>>s){
		printf("%4d.",turn++);
		if(s)print_ans(s);
		else cout<<" 0";
		cout<<endl;	
	}

	return 0;
}
```
