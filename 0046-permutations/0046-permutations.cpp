class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int>& path,vector<bool>& vis){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                path.push_back(nums[i]);
                vis[i]=true;
                solve(nums,path,vis);
                path.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        vector<int> path;
        solve(nums,path,vis);
        return ans;
    }
};