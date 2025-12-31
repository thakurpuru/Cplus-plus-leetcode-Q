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
                        
                        dist[v]=d+wt;
                        q.push({dist[v],v});
                    }
                }
            }

        
        
        vector<int>dp(n,-1);
        function<int(int)> dfs=[&](int src){
            
            if(src==n-1) return 1;
            if(dp[src]!=-1) return dp[src];
            long long ans=0;
            for(auto [v,wt]:g[src]){
                if(dist[v]==dist[src]+wt){
                    ans=(ans+dfs(v))%mod;
                }
            }
            return dp[src]=ans;

        };
        
        return dfs(0);
    }
};