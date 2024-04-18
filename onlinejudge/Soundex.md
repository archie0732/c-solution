```cpp
#include<bits/stdc++.h>

using namespace std;

string board="BFPVCGJKQSXZDTLMNR";

int main(){

	string s;
	int last=-1;
	while(getline(cin,s)){
		string ans="";
		for(int i=0;i<s.size();i++){
			auto it = board.find(s[i]);
		 	if(it>=0&&it<4 && (last>=4||last==-1))ans+="1";
			else if(it>=4&&it<=11 && (last>11||last<4))ans+="2";
			else if((it==12||it==13)&&last!=12&&last!=13)ans+="3";
			else if(it==14&&last!=14)ans+="4";
			else if((it==15||it==16) && last!=15 && last!=16)ans+="5";
			else if(it==17&&last!=17)ans+="6";
		
			last = it;
		}
		cout<<ans<<endl;
	}

}
```


```cpp
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>


using namespace std;



string board_1 = "BFPV";
string board_2 = "CGJKQSXZ";
string board_3 = "DT";
string board_4 = "L";
string board_5 = "MN";
string board_6 = "R";
int main()
{
    string s;
    while (cin >> s)
    {

        string ans = "";
        char c = '-';
        int pre = 0;
        for (int i = 0;i < s.size();i++)
        {

            if (s[i] == ' ')continue;
            if (board_1.find(s[i]) != -1)
            {
                if (pre != 1 && s[i] != c)
                {
                    c = s[i];
                    ans += "1";
                    pre = 1;
                }
            }
            else if (board_2.find(s[i]) != -1)
            {
                if (pre != 2 && s[i] != c)
                {
                    c = s[i];
                    ans += "2";
                    pre = 2;
                }
            }
            else if (board_3.find(s[i]) != -1)
            {
                if (pre != 3 && s[i] != c)
                {
                    c = s[i];
                    ans += "3";
                    pre = 3;
                }
            }
            else if (board_4.find(s[i]) != -1)
            {
                if (pre != 4 && s[i] != c)
                {
                    c = s[i];
                    ans += "4";
                    pre = 4;
                }
            }
            else if (board_5.find(s[i]) != -1)
            {
                if (pre != 5 && s[i] != c)
                {
                    c = s[i];
                    ans += "5";
                    pre = 5;
                }
            }
            else if (board_6.find(s[i]) != -1)
            {
                if (pre != 6 && s[i] != c)
                {
                    c = s[i];
                    ans += "6";
                    pre = 6;
                }
            }
            else
            {
                c = '-';
                pre = 0;
            }
        }
        std::cout << ans << endl;
    }

    return 0;
}
```
