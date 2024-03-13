#include<iostream>
#include<vector>


// 有可能原來手上的牌只有一張 ==> 不要空格
// 還有記得逗號最後不要加
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int>card;

        for (int i = 1;i <= n;i++)card.push_back(i);

        cout << "Discarded cards:";
        if (n != 1)cout << " ";
        while (card.size() > 1)
        {
            cout << card.front();
            if (card.size() != 2)cout << ", ";
            card.erase(card.begin());
            card.push_back(card.front());
            card.erase(card.begin());
        }
        cout << endl << "Remaining card: " << card.front() << endl;

    }

    return 0;
}
