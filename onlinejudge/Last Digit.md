# Last Digit 

[題目連結](https://vjudge.net/problem/Uva-10162)


* 20 個一個小規律(比前一循環多+4)，直到100
* 輸入可能超大(用字串去找)
* 輸出前要再取`mod10`


#### code


```cpp
#include<bits/stdc++.h>

using namespace std;

//                        4   
vector<int> board={0,1,5,2,8,3,9,2,8,7,7,8,4,7,3,8,4,1,5,4};

int main(){

	string s;

	while(cin>>s&&s!="0"){
		
		int n = s[s.size()-1]-'0';
		if(s.size()>1)n+=(s[s.size()-2]-'0')*10;
		
		cout<<(board[n%20]+(n/20)*4)%10<<endl;
	}

	return 0;
}
```
