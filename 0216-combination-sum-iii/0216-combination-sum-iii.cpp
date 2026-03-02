class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &path,int k,int n,int sum,int start){
        if(sum==n && path.size()==k){
            ans.push_back(path);
            return;
        }
        if(sum>n || path.size()>k) return ;
        for(int i=start;i<=9;i++){
            path.push_back(i);
            backtrack(path,k,n,sum+i,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n) return ans;
        vector<int> path;
        backtrack(path,k,n,0,1);
        return ans;
    }
};