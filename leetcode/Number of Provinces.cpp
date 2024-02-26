//Number of Provinces
//mid
class Solution {
public:
    int Find_(vector<int> &f,int x){
        if(f[x] != x){
            f[x] = Find_(f,f[x]);
        }
        return f[x];
    }
    void merge(vector<int> &f,vector<int> &rank,int x,int y){
        x = Find_(f,x);
        y = Find_(f,y);

        if(x==y) return;

        if(x < y){
            swap(x,y);
        }

        f[y] = x;
        rank[x] += rank[y];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> f(n),rank(n);

        for(int i = 0;i < n;i++){
            f[i] = i;
            rank[i] = 1;
        }
        
        map<int,int> have;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(i != j && isConnected[i][j] == 1){
                    // if have j root
                    if(have.count(j)){
                        merge(f,rank,i,have[j]);
                    }
                    else{
                        have[j] = i;
                    }
                }
            }
            if(have.count(i)){
                merge(f,rank,i,have[i]);
            }
            else{
                have[i] = i;
            }
        }
        set<int> ans;
        //find root
        for(int i = 0;i < n;i++){
            ans.insert(Find_(f,i));
        }
        return ans.size();
    }
};
