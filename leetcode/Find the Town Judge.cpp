//Find the Town Judge
//easy

//note
/*
 *[1,2]代表1信任2
 *所有人都相信法官
 *法官不相信任何人
 *所以只要有一位被所有人信任且不相信任何人的人出現就是法官
*/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1)return 1;
        map<int,int> in;
        map<int,int> out;
        //1==>2
        for(int i=0;i<trust.size();i++){
            in[trust[i][0]]++;
            out[trust[i][1]]++;
        }
        int flag=0,ans;
        for(auto it :out){
            if(it.second==n-1){
                flag=1;
                ans=it.first;
            }
        }
        if(in[ans]==0&&flag){
            return ans;
        }
        return -1;
    }
};
