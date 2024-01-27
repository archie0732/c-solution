# Mutant Flatworld Explorers

[題目連結](https://vjudge.net/problem/UVA-118)


#### 解題

* 因為一度搞錯題意，程式碼超混亂的XD

* 一樣，建表==>當機器人調出世界時查看期前一步，如果前一部沒有紀錄，那就掉出世界，並記錄
* 如果有紀錄過，那就忽略那一步


#### code


```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;


char rdir;

pair<int, int> walk(int x, int y, char c)
{
  map<char, vector<char>> dire;
  dire['N'] = { 'W','N','E' };
  dire['S'] = { 'E','S','W' };
  dire['E'] = { 'N','E','S' };
  dire['W'] = { 'S','W','N' };



  if (c == 'F')
  {
    if (rdir == 'N')
    {

      return make_pair(x, y + 1);
    }
    else if (rdir == 'S')
    {
      return make_pair(x, y - 1);
    }
    else if (rdir == 'E')
    {
      return make_pair(x + 1, y);
    }
    else if (rdir == 'W')
    {
      return make_pair(x - 1, y);
    }
  }
  else
  {
    if (c == 'L')
    {
      char tem = rdir;
      rdir = dire[tem][0];
      return make_pair(x, y);
    }
    else if (c == 'R')
    {
      char tem = rdir;
      rdir = dire[tem][2];
      return make_pair(x, y);
    }
  }
  return { x,y };
}



int main(int argc, char const* argv[])
{
  int turn = 1;
  const vector<char>dir = { 'E','N','W','S' };
  pair<int, int> lost_side;

  cin >> lost_side.first >> lost_side.second;
  cin.ignore();

  pair<int, int>bs;
  set< pair<int, int>> check;
  string s;
  // input
  while (cin >> bs.first >> bs.second >> rdir)
  {
    int flag = 0;
    cin >> s;
    //cout << s[0] << endl;
    vector <pair<int, int>>temp;
    for (int i = 0;i < s.length();i++)
    {

      //backup
      pair<int, int>backup = bs;
      char c = rdir;

      //debug backup
      //cout << "backup:" << backup.first << " " << backup.second << " " << rdir << endl;

      //walk
      bs = walk(bs.first, bs.second, s[i]);


      // is_lost?
      if ((bs.first < 0 || bs.second < 0 || bs.first > lost_side.first || bs.second > lost_side.second))
      {

        if (check.count(backup))
        {

          bs = backup;
          rdir = c;
          //cout << "suceed backup: " << backup.first << " " << backup.second << endl;
        }
        else
        {
          check.insert(backup);
          bs = backup;
          rdir = c;
          flag = 1;
        }
      }
      //cout << turn << ": " << bs.first << " " << bs.second << " " << rdir << " " << flag << endl;
      //turn++;

      if (flag == 1)
      {
        break;
      }


    }//for loop end

    //output
    cout << bs.first << " " << bs.second << " " << rdir;
    if (flag == 1)
    {
      cout << " LOST";
    }
    cout << endl;

    //insert to check
    for (int i = 0;i < temp.size();i++)
    {
      check.insert(temp[i]);
    }

    // debug check;
    //cout << endl << "check:";
    /*for (auto it : check)
    {
      cout << it.first << " " << it.second << endl;
    }
    cout << endl;*/

  }

  return 0;
}
```
