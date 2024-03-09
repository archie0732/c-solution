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
