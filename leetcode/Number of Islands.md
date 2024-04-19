#  Number of Islands

[題目連結](https://leetcode.com/problems/number-of-islands/description/?envType=daily-question&envId=2024-04-19)

* 直接遍歷去找上下左右有沒有1

#### code



```cpp
class Solution {
public:
    void findIsland(vector<vector<char>>& a,int x,int y){
        if(x>0&&a[x-1][y]=='1'){
            a[x-1][y]='/';
            findIsland(a,x-1,y);
        }
        if(x<a.size()-1 && a[x+1][y]=='1'){
            a[x+1][y]='/';
            findIsland(a,x+1,y);
        }
        if(y>0 && a[x][y-1]=='1'){
            a[x][y-1]='/';
            findIsland(a,x,y-1);
        }
        if(y<a[0].size()-1 && a[x][y+1]=='1'){
            a[x][y+1]='/';
            findIsland(a,x,y+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    findIsland(grid,i,j);
                    ans++;
                }
            }
        }

        for(auto it:grid){
            for(auto it2 : it){
                cout<<it2<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};
```
