class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(),nums.end());
        int check=original;

        while(st.count(check)){
            check*=2;
        }
        return check;
    }
};