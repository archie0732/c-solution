//Redundant Connection
//mid
class Solution {

    int Find_(vector<int> &f,int x){
        if(f[x] != x){
            f[x] = Find_(f,f[x]);
        }
        return f[x];
    }

    void merge(vector<int> &f,vector<int> &rank,int x,int y){
        x = Find_(f,x);
        y = Find_(f,y);

        if(x==y)return;

        if(x < y){
            swap(x,y);
        }
        f[y] = x;
        rank[x] += rank[y];
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    
        int n = edges.size();
        vector<int> f(n+1),rank(n+1);

        for(int i = 0;i <= n;i++){
            f[i] = i;
            rank[i] = 1;
        }

        map<int,int> have;
        vector<vector<int>> ans;
    
        for(int i = 0;i<n;i++){
            int a = edges[i][0],b = edges[i][1];
            
            if(!have.count(a) && !have.count(b)){
                have[a] = a;
                have[b] = b;
                f[a] = a;
                f[b] = a;
            }
            else if(!have.count(a) && have.count(b)){
                have[a] = b;
                f[a] = b;
            }
            else if(have.count(a) && !have.count(b)){
                have[b] = b;
                f[b] = a;
            }
            else{
                int c1 = Find_(f,a);
                int c2 = Find_(f,b);
                if(c1 == c2){
                    ans.push_back({a,b});
                }
                else{
                    merge(f,rank,a,b);
                }
            }
        }
        return ans.back();
    }
};
