# Relational Operators 

[題目連結](https://vjudge.net/problem/UVA-11172)


* 用BigInteger 一下解決(java)

![](https://i.pixiv.cat/img-original/img/2024/03/07/22/40/58/116709250_p0.jpg)

#### code (java)


```java
import java.util.*;
import java.math.*;

public class Relational_Operators {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {

            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();

            int res = a.compareTo(b);

            if (res > 0) {
                System.out.println(">");
            } else if (res < 0) {
                System.out.println("<");
            } else {
                System.out.println("=");
            }
        }

        sc.close();
    }

}
```

#### code (cpp)
```cpp
#include<iostream>
#include<string>



using namespace std;


int main()
{

    int t;

    cin >> t;
    while (t--)
    {

        string s, s2;
        int flag = 0, winner;

        cin >> s >> s2;
        int n1 = 0, n2 = 0;

        //長度不同
        if (s.size() != s2.size())
        {
            flag = 1;
            if (s[0] == '-' && s2[0] == '-')
            {
                winner = s.size() > s2.size() ? 2 : 1;
            }
            else if (s[0] == '-')
            {
                winner = 2;
            }
            else if (s2[0] == '-')
            {
                winner = 1;
            }
            else
            {
                winner = s.size() > s2.size() ? 1 : 2;
            }
        }

        if (s[0] == '-')n1 = 1;
        if (s2[0] == '-')n2 = 1;

        if ((n1 == 0 && n2 == 0))
        {
            for (int i = 0;i < s.size() && flag == 0;i++)
            {
                if (s[i] != s2[i])
                {
                    flag = 1;
                    winner = (s[i] - '0') > (s2[i] - '0') ? 1 : 2;
                    break;
                }
            }
        }

        if ((n1 == 1 && n2 == 1))
        {
            for (int i = 1;i < s.size() && flag == 0;i++)
            {
                if (s[i] != s2[i])
                {
                    flag = 1;
                    winner = (s[i] - '0') > (s2[i] - '0') ? 2 : 1;
                    break;
                }
            }
        }

        if (n1 == 0 && n2 != 0 && flag == 0)
        {
            flag = 1;
            winner = 1;
        }
        if (n1 != 0 && n2 == 0 && flag == 0)
        {
            flag = 1;
            winner = 2;
        }



        if (flag)
        {
            cout << (winner == 1 ? '>' : '<') << endl;
        }
        else cout << '=' << endl;

    }


    return 0;
}
```
