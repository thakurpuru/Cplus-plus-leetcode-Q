class Solution {
public:
    vector<vector<int>> ans;
    vector<bool> vis;
    void permutation(vector<int>& nums,vector<int>& path,int i){
        if(i==nums.size()){
            ans.push_back(path);
            return;
        }

        for(int j=0;j<nums.size();j++){
            if(!vis[j]){
                path.push_back(nums[j]);
                vis[j]=true;
                permutation(nums,path,i+1);
                path.pop_back();
                vis[j]=false;

            }

            
        }
                
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vis.assign(n,false);
        vector<int> path;
        permutation(nums,path,0);
        return ans;
    }
};