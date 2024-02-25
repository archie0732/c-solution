//Greatest Common Divisor Traversal
//hard
class Solution {
    // DSU
    int Find_(vector<int>&f,int x){
        if(f[x] != x){
            f[x] = Find_(f,f[x]);
        }
        
        return f[x];
    }
    // merge (compress array pointer)
    void merge(vector<int>&f,vector<int>&size,int x,int y){
        x = Find_(f,x);
        y = Find_(f,y);
        // if both have same root
        if(x == y)return;
        // let x rank  >  y rank
        if(size[x]<size[y]){
            swap(x,y);
        }
        // 合併
        f[y] = x;
        // for anwer
        size[x]+=size[y];
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        
        const int n = nums.size();
        
        if(n == 1) return true;
        // create a dsu board
        vector<int> f(n),size(n);

        for(int i=0;i<n;i++){

            //root is thierself 
            f[i] = i;
            
            //all size = 1
            size[i] = 1;
        }

        // store the point is root
        map<int,int> have;
        
        //find common root
        for(int i=0;i<n;i++){
            int num = nums[i];
            if(num==1)return false;

            for(int d = 2;d * d <= num;d++){
            
                if(num % d == 0){

                    if(have.count(d)) merge(f,size,i,have[d]);
                    else have[d] = i;

                    while(num % d == 0) num/= d; 
                }
            }

            if(num > 1){
            
                if(have.count(num)) merge(f,size,i,have[num]);
                else have[num] = i;
            }

        }      
        return size[Find_(f,1)] == n;
    }
};
