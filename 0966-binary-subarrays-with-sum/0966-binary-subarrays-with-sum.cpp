class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int ans=0,j=0;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(j<=i && sum>goal){
                sum-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
    }
};