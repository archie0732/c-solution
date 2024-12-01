//https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        set<int> st;
        for(int num : arr){
            if(st.count(num * 2) || (num % 2 == 0 && st.count(num / 2)))
                return true;
            st.insert(num);
        }

        return false;
    }
};
