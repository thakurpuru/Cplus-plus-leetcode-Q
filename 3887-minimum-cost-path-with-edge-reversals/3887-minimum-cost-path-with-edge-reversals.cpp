class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        
        for(auto v:edges){
            graph[v[0]].push_back({v[1],v[2]});
            graph[v[1]].push_back({v[0],2*v[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dest(n,INT_MAX);
        vector<bool> vis(n,false);
        pq.push({0,0});
        dest[0]=0;
        while(!pq.empty()){
            auto [d,u]=pq.top();
            pq.pop();
            if (vis[u])
            continue;
            vis[u]=true;
            for(auto [v,w]:graph[u]){
                if(dest[v]>dest[u]+w){
                   dest[v]=dest[u]+w;
                   pq.push({dest[v],v});
                }
            }
        }
        

        return dest[n-1]==INT_MAX?-1:dest[n-1];
    }
};