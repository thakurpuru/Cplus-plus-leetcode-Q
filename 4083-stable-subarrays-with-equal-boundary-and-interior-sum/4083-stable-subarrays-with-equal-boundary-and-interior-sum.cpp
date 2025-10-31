class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long ans=0;
        int n=capacity.size();
        long long prefix=0;
        if(n<3) return 0;
        unordered_map<long long,unordered_map<long long,long long>>mpp;
        
        for(int i=0;i<n;i++){
            if(mpp.count(capacity[i]) && mpp[capacity[i]].count(prefix-capacity[i])){
                ans+=mpp[capacity[i]][prefix-capacity[i]];
            }

            prefix+=capacity[i];
            mpp[capacity[i]][prefix]++;
            if(i>0 && capacity[i]==0 && capacity[i-1]==0) ans--;
        }
        return ans;
        
    }
};