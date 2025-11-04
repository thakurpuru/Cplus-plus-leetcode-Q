class Solution {
public:
    bool compare(const pair<int,int>& p1,const pair<int,int>& p2){
        if(p1.second==p2.second) return p1.first>p2.first;
        return p1.second>p2.second;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        if(k==x){
            int t=0;
            int j=0;
            for(int i=0;i<nums.size();i++){
                t+=nums[i];
                if (i-j+1==x){
                    ans.push_back(t);
                    t-=nums[j];
                    j++;
                }
            }
            return ans;
        }else{

            vector<pair<int,int>> vec(mp.begin(),mp.end());
                sort(vec.begin(),vec.end(),[](const auto& p1, const auto& p2){
            if (p1.second == p2.second)
                return p1.first > p2.first;
            return p1.second > p2.second;
        });
            int temp=0;
            for(int i=0;i<vec.size() && i<x;i++){
                temp+=(vec[i].first*vec[i].second);
            }
            ans.push_back(temp);
        }
        int n=nums.size();
        int j=0;
        for(int i=k;i<n;i++){
            mp[nums[i]]++;
            mp[nums[j]]--;
            j++;
            vector<pair<int,int>> vec(mp.begin(),mp.end());
                sort(vec.begin(),vec.end(),[](const auto& p1, const auto& p2){
            if (p1.second == p2.second)
                return p1.first > p2.first;
            return p1.second > p2.second;
        });
            int temp=0;
            for(int j=0;j<vec.size() && j<x;j++){
                temp+=(vec[j].first*vec[j].second);
            }
            ans.push_back(temp);
            temp=0;
        

        }
        
        return ans;
    }
};