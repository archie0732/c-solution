class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        if(A[0] == B[0])ans[0]++;

        set<int>s;
        s.insert(A[0]);
        s.insert(B[0]);

        for(int i = 1 ; i < n ; i++){
            ans[i] = ans[i - 1];
            if(s.count(A[i])){
                ans[i]++;
            }

            s.insert(A[i]);

            if(s.count(B[i])){
                ans[i]++;
            }

            s.insert(B[i]);
        }

        return ans;
    }
};
