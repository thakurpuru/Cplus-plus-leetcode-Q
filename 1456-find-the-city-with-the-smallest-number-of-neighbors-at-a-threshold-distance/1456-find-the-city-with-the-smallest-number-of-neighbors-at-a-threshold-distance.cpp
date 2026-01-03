class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> g(n);
        for(auto &e:edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        int ans=-1;
        int mincount=INT_MAX;
        for(int src=0;src<n;src++){
            vector<int> dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
            dist[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                auto [d,u]=pq.top();
                pq.pop();
                for(auto [v,wt]:g[u]){
                    if(dist[v]>dist[u]+wt){
                        dist[v]=dist[u]+wt;
                        pq.push({dist[v],v});
                    }
                }
            }

            int count=0;
            for(int i=0;i<n;i++){
                if(i!=src && dist[i]<=distanceThreshold){
                    count++;
                }
            }
            if(count<mincount || (count==mincount && src>ans)){
                mincount=count;
                ans=src;
            }

        }
        return ans;
    }
};