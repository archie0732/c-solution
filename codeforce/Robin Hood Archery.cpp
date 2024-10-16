#include <iostream>
#include <vector>
#include <string>
#include <functional> // for std::hash

using namespace std;

// 簡單的哈希函數，用來替代 Python 的 hash()
size_t hash_fn(const string &s)
{
    hash<string> str_hash; // 創建哈希對象
    return str_hash(s);    // 調用哈希對象
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<size_t> xors(n + 1, 0); // 用來儲存前綴哈希異或值

        // 讀取數組並計算前綴異或值
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i - 1];
            xors[i] = xors[i - 1] ^ hash_fn(to_string(a[i - 1]));
        }

        // 處理每個查詢
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << ((xors[r] ^ xors[l - 1]) ? "NO" : "YES") << endl;
        }
    }

    return 0;
}
