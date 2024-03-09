# Contest Scoreboard 

[題目連結](https://vjudge.net/problem/UVA-10258)




#### 解題

* 沒過(I): error加1
* 通過(C):完成時間+error次數*20


排序(相同在比下面的)  

1. 對的題數
2. 總花費時間
3. 隊伍排序


#### code


```cpp

#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;

struct Team
{
    bool join;
    int num;
    int score;
    int problem;
    int error[10];
};

bool compare(Team a, Team b)
{
    if (a.problem > b.problem) return true;
    if (a.problem < b.problem) return false;
    if (a.score < b.score) return true;
    if (a.score > b.score) return false;
    if (a.num < b.num) return true;
    return false;
}

int main()
{
    int testcase;
    string entry;
    stringstream ss;
    Team teams[105];
    int contestant, problem, time;
    char L;

    while (scanf("%d", &testcase) != EOF)
    {
        getchar();
        getchar();
        for (int i = 0; i < testcase; i++)
        {
            if (i) printf("\n");
            for (int j = 0; j < 105; j++)
            {
                teams[j].join = 0;
                teams[j].num = j;
                teams[j].score = 0;
                teams[j].problem = 0;
                memset(teams[j].error, 0, sizeof(teams[j].error));
            }

            while (getline(cin, entry) && entry != "")
            {
                ss.clear();
                ss.str(entry);
                ss >> contestant >> problem >> time >> L;

                teams[contestant].join = true;
                if (teams[contestant].error[problem] == -1) continue;
                if (L == 'C')
                {
                    teams[contestant].score += time + teams[contestant].error[problem] * 20;
                    teams[contestant].problem++;
                    teams[contestant].error[problem] = -1;
                }
                else if (L == 'I')
                    teams[contestant].error[problem]++;
            }
            sort(teams, teams + 105, compare);
            for (int j = 0; j < 105; j++)
                if (teams[j].join)
                    printf("%d %d %d\n", teams[j].num, teams[j].problem, teams[j].score);
        }
    }
    return 0;
}
```


