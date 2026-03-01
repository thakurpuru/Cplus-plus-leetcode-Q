class Solution {
public:
    vector<vector<int>> ans;
    void subset(vector<int>& nums,vector<int>& path,int i){
        
        ans.push_back(path);
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1] ) continue;
           
                path.push_back(nums[j]);
                subset(nums,path,j+1);
                path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      
        vector<int> path;
        sort(nums.begin(),nums.end());
        subset(nums,path,0);
        return ans;
    }
};