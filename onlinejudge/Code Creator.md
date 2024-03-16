#  Code Creator


[題目連結]()


* 水題，注意特殊字元，ex:`"` `'` `\`


#### code 


```cpp
#include<iostream>
#include<vector>
#include<stdio.h>


using namespace std;



int main(){
	
	int t,turn=1;
	
	
	while(cin>>t&&t){
		getchar();
		cout<<"Case "<<turn++<<":"<<endl;
		cout<<"#include<string.h>"<<endl<<"#include<stdio.h>"<<endl<<"int main()"<<endl<<"{"<<endl;
		string s;
		for(int i=0;i<t;i++){
		
			getline(cin,s);
			
			cout<<"printf(\"";
			
			for(int i=0;i<s.size();i++){
				if(s[i]=='\''||s[i]=='"'||s[i]=='\\'){
					cout<<'\\'<<s[i];
				}
				else{
					cout<<s[i];
				}
			}
			cout<<"\\n\");"<<endl;
		}
		
		
		cout<<"printf(\"\\n\");"<<endl<<"return 0;"<<endl<<"}"<<endl;
		
	}


	return 0;
}
```
