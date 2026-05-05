class Solution {
public:
    void dfs(int src,vector<bool>& vis,vector<vector<int>>& g){
        vis[src]=true;
        for(int v:g[src]){
            if(!vis[v]){
                dfs(v,vis,g);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<vector<int>> g(n);
        for(auto v:connections){
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
        }
        int con=0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,g);
                con++;
            }
        }
        return con-1;

    }
};