class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> gr(n);
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    gr[i].push_back(j);
                    gr[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        function<void(int)> dfs=[&](int src){
            vis[src]=true;
            for(auto v:gr[src]){
                if(!vis[v]){
                    dfs(v);
                }
            }
        };
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};