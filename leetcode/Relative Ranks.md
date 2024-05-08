# Relative Ranks


[Q link](https://leetcode.com/problems/relative-ranks/?envType=daily-question&envId=2024-05-08)



#### code

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        string bt[3];
        bt[0] = "Gold Medal";
        bt[1] = "Silver Medal";
        bt[2] = "Bronze Medal";
        vector<string> ans(score.size(),"a");
        
        for(int flag=0;flag<score.size();flag++){
            int side=0,mx=-1;
            for(int i=0;i<score.size();i++){
                if(score[i]>mx){
                    
                    mx = score[i];
                    side = i;
                }
            }
            cout<<score[side]<<" "<<flag<<endl;
            ans[side] = (flag >= 3)? to_string(flag+1) : bt[flag];
            score[side] = -11;
        }

        return ans;

    }
};
```
