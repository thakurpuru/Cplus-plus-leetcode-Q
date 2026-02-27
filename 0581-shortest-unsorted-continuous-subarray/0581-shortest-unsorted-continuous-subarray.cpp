class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int j=-1,k=-1;
        int max_s=nums[0],n=nums.size();
        for(int i=1;i<nums.size();i++){
            if(nums[i]<max_s){
                j=i;
            }else {
                max_s=nums[i];
            }

        }
        if(j==-1) return 0;
        int min_s=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>min_s){
                k=i;
            }else {
                min_s=nums[i];
            }

        }
        return j-k+1;

    }
};