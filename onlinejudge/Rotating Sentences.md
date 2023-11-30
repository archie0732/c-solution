# Rotating Sentences

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


#### code 
```cpp
#include <iostream>
#include <vector>
#include <string>
#define size 101

using namespace std;

int main(int argc, char const *argv[])
{
    string s[size];
    int maxlenght = 0;
    int n = 0;
    while (getline(cin, s[n]))
    {
        if (s[n].length() > maxlenght)
        {
            maxlenght = s[n].length();
        }
        n++;
    }

    
    for (int i = 0; i < maxlenght; i++)
    {
        for (int j = n; j >= 0; j--)
        {
            if (s[j].length() > i)
                cout << s[j][i];
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
```
