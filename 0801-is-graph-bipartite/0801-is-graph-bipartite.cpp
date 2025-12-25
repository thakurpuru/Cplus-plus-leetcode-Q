class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> path(n,-1);

        function<bool(int,int)> iscycle=[&](int src,int c){
            path[src]=c;
           
            for(auto v:graph[src]){
                if(path[v]==-1){
                    if(!iscycle(v,1-c)) return false;
                }else if(path[v]==c){
                    return false;
                }
            }
        
            return true;
        };
        for(int i=0;i<n;i++){
            if(path[i]==-1){
                if(!iscycle(i,0)) return false;
            }
        }
        return true;
    }
};