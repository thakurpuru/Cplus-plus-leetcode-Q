class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph,int node,vector<bool> &vis,vector<int>& res){
        vis[node]=true;
        res.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(res);
            
        }
        for(auto v:graph[node]){
            if(!vis[v]){
                dfs(graph,v,vis,res);
            }
        }
        res.pop_back();
        vis[node]=false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> res;
        vector<bool> vis(n,false);
        dfs(graph,0,vis,res);
        return ans;

    }
};