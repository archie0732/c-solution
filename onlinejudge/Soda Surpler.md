# Soda Surpler 


[題目連結](https://vjudge.net/problem/UVA-11689)

* 題目是說**額外的**汽水(不含原來就有的)

#### code


```cpp
#include<iostream>

using namespace std;


int main(){
	
	int t;
	cin>>t;
	while(t--){
		int have ,give,rec,sum=0;
		cin>>have>>give>>rec;
		
		int b = have+give;
		
		while(b>=rec){
			sum+=b/rec;
			b=b%rec+b/rec;
		}
		
		cout<<sum<<endl;
		
	}
	return 0;
}
```
