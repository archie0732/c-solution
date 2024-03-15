#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long 
#define promble_url https://vjudge.net/problem/UVA-11000


using namespace std;

vector<pair<ll, ll>> board(1000);

/*
 * 解題: 母的有一隻永遠不會死
 * 用推的找規律 
*/


void make_board()
{
    // female = first : male = second
    board[0].first = 1;
    board[0].second = 0;
    board[1].first = 1;
    board[1].second = 1;

    for (int i = 2;i < 1000;i++)
    {
        board[i].first = board[i - 1].second + 1;
        board[i].second = board[i - 1].first + board[i - 1].second;
    }

}


int main()
{

    // female ==> 1 male (1f + 1m )
    // male ==> 1 male 1 female (1+1)
    int f = 1, m = 0;

    // 1 : 0 ==> 1 : 1 ==> 1+1 : 1+1  ==> 2+1(3) : 2+2(4) ==> 1+4 : 4+3 ... ==> 1+(m_(n-1)) : (m_(n-1))+(f_(n-1)) 

    int N;
    int dead = 0;
    make_board();
    while (cin >> N && N >= 0)
    {
        cout << board[N].second << " " << board[N].first + board[N].second << endl;
    }

    return 0;
}
