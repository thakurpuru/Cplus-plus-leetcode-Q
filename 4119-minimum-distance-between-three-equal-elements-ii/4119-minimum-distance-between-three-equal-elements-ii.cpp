class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mp;
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            mp[nums[i]].push_back(i);
            if(count[nums[i]]>=3){
                int n=mp[nums[i]].size()-1;
                int dist=2*(mp[nums[i]][n]-mp[nums[i]][n-2]);
                ans=min(ans,dist);
            }
            
        }
        // for(auto &m:mp){
            
        //     if(m.second.size()>=3){
        //         for(int a=0;a+2<m.second.size();a++){
        //            int sum=2*(m.second[a+2]-m.second[a]);
        //             ans=min(ans,sum);
        //         }
        //     }
        // }
         return ans == INT_MAX ? -1 : ans;
    }
};