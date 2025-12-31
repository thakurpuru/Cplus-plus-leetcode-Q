class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        for(auto r:roads){
            g[r[0]].push_back({r[1],r[2]});
            g[r[1]].push_back({r[0],r[2]});
        }
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>q;
        vector<long long>ways(n,0);
        dist[0]=0;
            ways[0]=1;
            q.push({0,0});
            while(!q.empty()){
                auto [d,u]=q.top();
                q.pop();

            if (d > dist[u]) continue;
                for(auto [v,wt]:g[u]){
                    if(dist[v]>d+wt){
                        ways[v]=ways[u];
                        dist[v]=d+wt;
                        q.push({dist[v],v});
                    }else if(dist[v]==d+wt){
                        ways[v]=(ways[u]+ways[v])%mod;
                    }
                }
            }

        
        // int mincost=dist[n-1];
        // int count=0;
        // function<void(int,int)> dfs=[&](int src,int cost){
        //     vis[src]=true;
        //     if(src==n-1 && cost==mincost) count++;
        //     for(auto [v,wt]:g[src]){
        //         if(!vis[v]){
        //             dfs(v,cost+wt);
        //         }
        //     }
        //     vis[src]=false;

        // };
        // dfs(0,0);
        return ways[n-1];
    }
};