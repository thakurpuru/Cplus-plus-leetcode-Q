class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> ans;
    void permutation(vector<int>& nums,vector<int>& path,int i){
        if(i==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(j>0 && nums[j]==nums[j-1] && !vis[j-1])continue;
            if(!vis[j]){
                path.push_back(nums[j]);
                vis[j]=true;
                permutation(nums,path,i+1);
                vis[j]=false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        int n=nums.size();
        vis.assign(n,false);
        sort(nums.begin(),nums.end());
        permutation(nums,path,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};