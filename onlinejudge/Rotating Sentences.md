# Rotating Sentences
[題目連結](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=431)
* 題目

In “Rotating Sentences,” you are asked to rotate a series of input sentences 90 degrees clockwise. So
instead of displaying the input sentences from left to right and top to bottom, your program will display
them from top to bottom and right to left.

$`\textcolor{blue}{input}`$

As input to your program, you will be given a maximum of 100 sentences, each not exceeding 100   
characters long. Legal characters include: newline, space, any punctuation characters, digits, and lower
case or upper case English letters. (NOTE: Tabs are not legal characters.)  

$`\textcolor{blue}{output}`$  

The output of the program should have the last sentence printed out vertically in the leftmost column;  
the first sentence of the input would subsequently end up at the rightmost column.

$`\textcolor{red}{note}`$  
**輸入直到在終端機按下ctrl+z結束**  

#### 解題
$`\textcolor{blue}{要先知道以下條件}`$  

1. 沒有限制輸入到哪一排停止 ==>不知道會有幾排
2. 沒有限制到哪裡停止==>不知道每排有幾個字母

***
先看以下例子:  
hello  
c++!
根據規則轉換:
```
ch
+e
+l
!l
 o
```
可以發現一件事:  
將`hello`視為**s1**(char)  
`c++`視為**s2**(char)  

***
再來看範例:  
```
s2[0]s1[0]
s2[1]s1[1]
s2[2]s1[2]
s2[3]s1[3]
     s1[4]
```
只要依照$`s_n`$[0] $` s_{n-1}`$[0]......$`s_1`$[0]這樣排就行

***
* **關於空格**
在範例中可以看到**s1[4]** 的前面為空白  
因為s2的長度只有4格所以s2[4]**不存在**  


==>$`\textcolor{red}{所以在長度不夠的情況下以'\quad '來湊}`$
#### code 
![](https://github.com/archie0732/c-solution/blob/main/picture/ayaka008.jpg)
```cpp
#include<bits/stdc++.h>

using namespace std;

int main(){
	
	vector<string> v;
	string s;
	int len=0;
	
	while(getline(cin,s)){
		v.push_back(s);
		int n = s.size();
		len = max(n,len);	
	}
	
	for(int i=0;i<len;i++){
		for(int j=v.size()-1;j>=0;j--){
			
			if(v[j].size()>i)cout<<v[j][i];
			else if(j>0)cout<<' ';
		}
		cout<<endl;
	}

	return 0;
}
```
