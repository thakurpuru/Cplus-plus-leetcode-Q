class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int j=0;
        long long product=1;
        int res=0;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            while(j<=i && product>=k){
                product/=nums[j];
                j++;
            }
            res+=(i-j+1);
        }
        return res;
    }
};