class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> st(nums.begin(),nums.end());
        int i=0;

        while(i<nums.size()){
            if(nums[i]==original){
                original*=2;
                i=0;
            }else i++;
            
        }
        return original;
    }
};