class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums,vector<int> &path,int sum, int start,int target){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        if(sum>target) return;
        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            path.push_back(nums[i]);
            backtrack(nums,path,sum+nums[i],i+1,target);
            path.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,path,0,0,target);
        return ans;
    }
};