class Solution {
public:
    vector<int> vis;
    bool backtrack(vector<int>& nums,int k,int sum,int start,int target){
        if(k==0) return true;

        if(sum==target){
            return backtrack(nums,k-1,0,0,target);
        }
        for(int i=start;i<nums.size();i++){
            if(vis[i]) continue;

            if(i>start && nums[i]==nums[i-1] && !vis[i-1])continue;
            int num=nums[i];
            if(sum+num>target) continue;
            vis[i]=true;
            if(backtrack(nums,k,sum+num,i+1,target))return true;
            vis[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%k!=0) return false;
        vis.assign(nums.size(),false);
        int target=total_sum/k;
        sort(nums.begin(),nums.end());
        return backtrack(nums,k,0,0,target);

    }
};