class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        for(auto n:nums){
            cout<<n;
        }
        int i=0;
        int ans=1;
        int j=0;
        while(j<n){
            while(nums[j]>(long long)k*nums[i]) i++;
            ans=max(ans,j-i+1);
            j++;
        }
        return n-ans;
    
    }
};