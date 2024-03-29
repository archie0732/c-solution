# Sort! Sort!! and Sort!!!

[題目連結](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2296)

最近都在摸魚，進度點落後  
#### 解題

按照規則，比較 ==> 結束
取餘
>先放小的  
>如果相同
>>先放基數，然後偶數
>>>都是基數==>先大後小
>>>都是偶數==>先小後大


#### code (cpp/java)

```cpp
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else if ((a.first % 2 == 1 || a.first % 2 == -1) && (b.first % 2 == 1 || b.first % 2 == -1))
    {
        return a.first > b.first;
    }
    else if (a.first % 2 == 0 && b.first % 2 == 0)
        return a.first < b.first;
    else
        return a.first % 2 != 0;
}

int main()
{
    int n, d;
    while (cin >> n >> d)
    {
        cout << n << " " << d << endl;

        if (!(n + d))
            return 0;
        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = v[i].first % d;
        }
        sort(v.begin(), v.end(), cmp);

        for (auto it : v)
        {
            cout << it.first << endl;
        }
    }

    return 0;
}
```

```java
    import java.util.*;

    public class Sort_Sort_and_Sort {
        static int M, n;

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            while (true) {
                n = sc.nextInt();
                M = sc.nextInt();
                System.out.println(n + " " + M);
                if (M == 0 && n == 0) {
                    break;
                }
                ArrayList<Integer> array = new ArrayList<Integer>();
                for (int i = 0; i < n; i++) {
                    array.add(sc.nextInt());
                }
                Collections.sort(array, new cmp());
                for (int it : array) {
                    System.out.println(it);
                }
            }
            sc.close();
        }

        static class cmp implements Comparator<Integer> {
            @Override
            public int compare(Integer num1, Integer num2) {
                boolean isOdd1 = num1 % 2 != 0;
                boolean isOdd2 = num2 % 2 != 0;

                // 先排小的再排大的
                if (num1 % M != num2 % M) {
                    return Integer.compare(num1 % M, num2 % M);
                }

                // 基數先，由大到小
                if (isOdd1 && isOdd2) {
                    return Integer.compare(num2, num1);
                }
                // 偶數後，由小到大
                else if (!isOdd1 && !isOdd2) {
                    return Integer.compare(num1, num2);
                }

                // 其他情況，基數優先
                return isOdd1 ? -1 : 1;
            }
        }

    }
```
