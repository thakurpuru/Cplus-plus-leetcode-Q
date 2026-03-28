class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int j=0,count=0,ans=0;
        for(int i=0;i<nums.size();i++){

            mp[nums[i]]++;
            if(mp[nums[i]]==1) count++;
            while(count>k){
                mp[nums[j]]--;
                if(mp[nums[j]]==0){
                    count--;
                }
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int a=solve(nums,k);
       int b=solve(nums,k-1);
       return a-b;
    }
};