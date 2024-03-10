//uva 10282
#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<map>

using namespace std;


int main()
{

    string keyword, find_word;

    stringstream ss;
    string s;
    map<string, string>mymap;
    while (getline(cin, s) && s != "")
    {
        ss.clear();
        ss.str(s);
        ss >> find_word >> keyword;
        mymap[keyword] = find_word;
    }

    string h;
    while (cin >> h)
    {
        if (!mymap.count(h))
        {
            cout << "eh" << endl;
        }
        else
        {
            cout << mymap[h] << endl;
        }
    }



    return 0;
}
