class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod=1e9+7;
        unordered_map<int,int> mp,mp1;
        int n=nums.size();
        if(n<3 ) return 0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        long long count=0;
        for(int i=0;i<n;i++){
            int a=nums[i]*2;
            mp[nums[i]]--;
            if(mp[nums[i]]==0)  mp.erase(nums[i]);
            count+=(long long)mp1[2*nums[i]]* mp[2*nums[i]];
            mp1[nums[i]]++;
        }
        return count%mod;
    }
};