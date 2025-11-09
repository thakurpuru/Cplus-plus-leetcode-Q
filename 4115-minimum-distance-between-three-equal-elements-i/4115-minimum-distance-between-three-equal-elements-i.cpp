class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=1000;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &m:mp){
            if(m.second.size()>=3){
                int i=m.second[0],j=m.second[1],k=m.second[2];
                int sum=abs(i-j)+abs(j-k)+abs(k-i);
                ans=min(ans,sum);
                for(int a=3;a<m.second.size();a++){
                   i=m.second[a-2],j=m.second[a-1],k=m.second[a];
                    sum=abs(i-j)+abs(j-k)+abs(k-i);
                    ans=min(ans,sum);
                }
            }
        }
        if(ans==1000) return -1;
        return ans;
    }
};