#  List of Conquests

#### 解題

建議先學習以下method
1. map
2. map & auto
3. getline

**解題**  

簡單來說就是這座城市出現幾次然後記數輸出，  
但會有以些要注意的點
> 1. 人名會有空格       ==>用getline
> 2. 輸出要印出城市名字  ==>用`map`，既可以計數又可以記錄城市名稱

#### 另解

用`vector`

1. 相同==>不`push_back`，紀錄次數
2. 不同==>用`push_back`，次數為 1


#### code 

![](https://c-ssl.duitang.com/uploads/blog/202207/06/20220706165757_b0164.JPG)

```cpp
    #include <iostream>
    #include <vector>
    #include <set>
    #include <map>

    using namespace std;

    int main(int argc, char const *argv[])
    {
        int t;
        cin >> t;
        map<string, int> city;
        string Cityname, s;

        for (int i = 0; i < t; i++)
        {

            cin >> Cityname;
            getline(cin, s);
            city[Cityname]++;
        }
        for (const auto it : city)
        {
            cout << it.first << " " << it.second << endl;
        }
        return 0;
    }
```

