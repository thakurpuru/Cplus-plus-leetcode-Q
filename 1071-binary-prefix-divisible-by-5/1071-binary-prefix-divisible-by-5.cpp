class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        vector<bool> ans(n,false);
        for(int i=0;i<n;i++){
            res=(res*2+nums[i])%5;
            if(res==0) ans[i]=true;
            
        }
        return ans;
    }
};