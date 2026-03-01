class Solution {
public:
    vector<vector<int>> ans;
    void combine(vector<int>& nums,vector<int>& path,int sum,int target,int i){
        if(sum>target) return;
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int j=i;j<nums.size();j++){
            path.push_back(nums[j]);
            combine(nums,path,sum+nums[j],target,j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        combine(candidates,path,0,target,0); 
        return ans;  
    }
};