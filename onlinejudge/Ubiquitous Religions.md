[題目連結](https://vjudge.net/problem/UVA-10583)


### 解題

* 既然是`union-find` 就根題目意思串起來

>1. 如果兩個值`map`都沒有這個值就把他們串起來（其中一個自己當父節點）
>2. 如果其中一個有，另一個沒有，把沒有的串到有的
>3. 如果都有，用`merge`串起來

最後，用`for each`找共有幾個父節點


```cpp
#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

int Find_(vector<int> &f, int x)
{
    if (f[x] != x)
        f[x] = Find_(f, f[x]);

    return f[x];
}

void merge(vector<int> &f, vector<int> &nums, int x, int y)
{
    x = Find_(f, x);
    y = Find_(f, y);
    if (x == y)
        return;

    if (nums[x] < nums[y])
        swap(x, y);

    f[y] = x;
    nums[x] += nums[y];
}

int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;

    int turn = 1;

    while (n != 0 && m != 0)
    {
        vector<int> f(n + 1), size(n + 1);

        for (int i = 0; i <= n; i++)
        {
            f[i] = i;
            size[i] = 1;
        }
        map<int, int> have;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (have.count(a) && !have.count(b))
            {
                merge(f, size, b, have[a]);
                have[b] = a;
            }
            else if (!have.count(a) && have.count(b))
            {
                merge(f, size, a, have[b]);
                have[a] = b;
            }
            else if (!have.count(a) && !have.count(b))
            {
                f[b] = a;
                have[a] = a;
                have[b] = a;
            }
            else if (have.count(a) && have.count(b))
            {
                merge(f, size, a, b);
            }
        }
        set<int> ans;
        for (int i = 1; i <= n; i++)
        {
            ans.insert(Find_(f, i));
        }
        cout << "Case " << turn << ": " << ans.size() << endl;

        turn++;

        cin >> n >> m;
    }

    return 0;
}
```
