class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int one=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(one!=-1 && i-one-1<k){
                    return false;
                }
                one=i;

            }

        }
        return true;
    }
};