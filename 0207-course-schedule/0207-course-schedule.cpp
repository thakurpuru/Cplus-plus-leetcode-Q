class Solution {
public:
    vector<vector<int>> graph;
    bool iscycle(vector<bool> &vis,vector<bool>&recpath,int src){
        vis[src]=true;
        recpath[src]=true;
        for(auto v:graph[src]){
            if(!vis[v]){
                if(iscycle(vis,recpath,v)) return true;
            }else if(recpath[v]) return true;
        }
        recpath[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        graph.assign(n,vector<int>());
        vector<bool> vis(n,false),recpath(n,false);
        for(auto e: prerequisites){
            graph[e[0]].push_back(e[1]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscycle(vis,recpath,i)) return false;
            }
        }
        return true;

    }
};