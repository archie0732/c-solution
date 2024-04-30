# One-Two-Three

[題目連結](https://vjudge.net/problem/UVA-12289)


* `three` 5個字母
* `one` `two`3個字母

所以先看測值的size就可以判斷了

接下來看1跟2

`one`可以換得值如下
`_ne` `o_e` `on_`

這樣去判斷如果符合就是1，反之是2

```cpp
#include<bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();

        if(n==5){
            cout<<"3"<<endl;
        }
        else if(n==3){
            // one two on_ o_e _ne
            if((s[0]=='o'&&s[2]=='e')||(s[0]=='o'&&s[1]=='n')||(s[1]=='n'&&s[2]=='e')){
                cout<<"1"<<endl;
            }
            else{
                cout<<2<<endl;
            }
        }
        else{
            cout<<"fuck"<<endl;
        }
    }   
    return 0;
}
```
