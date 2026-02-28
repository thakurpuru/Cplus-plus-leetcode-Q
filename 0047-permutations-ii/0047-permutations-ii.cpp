class Solution {
public:
    vector<bool> vis;
    set<vector<int>> ans;
    void permutation(vector<int>& nums,vector<int>& path,int i){
        if(i==nums.size()){
            ans.insert(path);
            return;
        }
        for(int j=0;j<nums.size();j++){
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
        permutation(nums,path,0);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};