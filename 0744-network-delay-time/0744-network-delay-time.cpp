class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>g(n+1);
        for(auto t:times){
            g[t[0]].push_back({t[1],t[2]});
        }
        vector<bool> vis(n+1,false);

        function<void(int)> dfs=[&](int src){
            vis[src]=true;
            for(auto e:g[src]){
                if(!vis[e.first]){
                    dfs(e.first);
                }
            }
        };
        dfs(k);
        for(int i=1;i<=n;i++){
            if(!vis[i]) return -1;
        }
        queue<pair<int,int>> q;
    
        q.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        dist[0]=-1;
        while(!q.empty()){
            auto [d,u]=q.front();
            q.pop();
            for(auto [v,wt]:g[u]){
                if(dist[v]>d+wt){
                    dist[v]=d+wt;
                    q.push({dist[v],v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dist[i]);
        }
        return ans;


    }
};