class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
       long long sum=0,ans=LLONG_MIN;
       int j=0,n=nums.size();
       
       unordered_map<int,long long> mp;
       
       mp[0]=0;
       for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=(i+1)%k;
            if(mp.count(rem)){
                
                ans=max(ans,sum-mp[rem]);
                
            }
            if(!mp.count(rem)){
                mp[rem]=sum;
            }else{
                mp[rem]=min(mp[rem],sum);
            }
       }
       return ans;

    }
};