class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // arr[i] = sr[i].first mean val and sr[i].second = i mean index
        int n = arr.size();
        vector<pair<int,int>> sr(n);
        for(int i=0;i<n;i++){
            sr[i] = {arr[i],i};
        }

        vector<int>ans(n);
        sort(sr.begin(),sr.end());
        int cur = 1;
        int pre = INT_MAX;
        for(auto &[x,i]:sr){
            if(x>pre)cur++;

            ans[i] = cur;
            pre = x;
        }

        return ans;
    }
};
