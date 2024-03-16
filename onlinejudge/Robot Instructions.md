# Robot Instructions 

[題目連結]()

* 水題，注意SAME` `AS num

#### code


```cpp

#include<iostream>
#include<vector>



using namespace std;


int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, pos = 0, tem;

        cin >> n;

        vector<int>board(n);

        string s, s2;

        for (int i = 0;i < n;i++)
        {
            cin >> s;
            if (s[0] == 'L')
            {
                board[i] = -1;
                pos += -1;
            }
            else if (s[0] == 'R')
            {
                board[i] = 1;
                pos += 1;
            }
            else if (s[0] == 'S')
            {
                cin >> s2 >> tem;
                pos += board[tem - 1];
                board[i] = board[tem - 1];
            }
        }
        cout << pos << endl;
    }

    return 0;
}
```
