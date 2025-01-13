class Solution {
public:
    int minimumLength(string s) {
        map<char, int>mp;

        for(char c : s){
            mp[c]++;
        }
        int ans = 0;
        for(auto it : mp){
            cout<<it.first<<" ";
            int tem = it.second;
            ans += tem % 2 == 0 ? 2 : 1;
        }

        return ans;
    }
};
