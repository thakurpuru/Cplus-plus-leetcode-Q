class Solution {
public:
    unordered_map<int,vector<int>> mp;
    bool iscycle(int src,vector<bool>&vis,vector<bool>&recpath){
        vis[src]=true;
        recpath[src]=true;
        for(auto v:mp[src]){
            if(!vis[v]){
                
                if(iscycle(v,vis,recpath)) return true;
            }else if(recpath[v]) return true;
        }
        recpath[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            mp[u].push_back(v);
        }
        vector<bool> vis(numCourses,false), rec(numCourses,false);
        for(auto i:mp){
            if(!vis[i.first]){
                if(iscycle(i.first,vis,rec)) return false;
            }
        }
        return true;
    }
};