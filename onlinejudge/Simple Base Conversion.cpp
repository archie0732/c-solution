#include <iostream>
#include <sstream>

using namespace std;

int main()
{


    while (true)
    {

        string s;
        cin >> s;
        if (s[0] == '-')return 0;
        int n = s.size();
        if (s.substr(0, 2) == "0x")
        {
            int ans = 0;
            for (int i = 2;i < n;i++)
            {
                ans *= 16;
                ans += (s[i] >= '0' && s[i] <= '9' ? s[i] - '0' : s[i] - 'A' + 10);
            }
            cout << dec << ans << endl;
        }
        else
        {
            int ans = 0;
            for (int i = 0;i < n;i++)
            {
                ans *= 10;
                ans += s[i] - '0';
            }
            cout << "0x" << uppercase << hex << ans << endl;
        }
    }

    return 0;
}
