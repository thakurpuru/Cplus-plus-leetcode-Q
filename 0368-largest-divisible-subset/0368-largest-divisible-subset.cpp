class Solution {
public:
    // vector<int> solve(vector<int>& nums,int k,int pre,vector<vector<vector<int>>>& dp){
    //     int n=nums.size();
    //     if(k==n){
    //         return {};
    //     }
    //     if(!dp[k][pre+1].empty()) return dp[k][pre+1];
    //     vector<int> take;
    //     if(pre==-1 || nums[k]%nums[pre]==0){
            
    //         take=solve(nums,k+1,k,dp);
    //         take.insert(take.begin(),nums[k]);

    //     }
    //     auto skip=solve(nums,k+1,pre,dp);

    //     return dp[k][pre+1]=take.size()>skip.size()?take:skip;

    // }
    vector<int> nextIdx,dp;
    int helper(vector<int>& nums,int i){
        if(dp[i]!=-1) return dp[i];
        int maxlen=1;
        nextIdx[i]=-1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j]%nums[i]==0){
                int len=1+helper(nums,j);
                if(len>maxlen){
                    maxlen=len;
                    nextIdx[i]=j;
                }
            }
        }
        return dp[i]=maxlen;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        dp.assign(n,-1);
        nextIdx.assign(n,-1);
        sort(nums.begin(),nums.end());
        int maxlen=0;
        int best=-1;
        for(int i=0;i<n;i++){
            int len=helper(nums,i);
            if(len>maxlen){
                best=i;
                maxlen=len;
            }
        }
        vector<int> res;
        int curr=best;
        while(curr!=-1){
            res.push_back(nums[curr]);
            curr=nextIdx[curr];
        }
        return res;
    }
};