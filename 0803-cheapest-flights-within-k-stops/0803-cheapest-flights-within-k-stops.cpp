class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        vector<vector<pair<int,int>>> g(n);
        for(int i=0;i<flights.size();i++){
            g[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,int>> q;
        function<int()> bfs=[&](){
            int count=0;
            q.push({0,src});
            while(!q.empty() && count<=k){
                int size=q.size();
                for(int i=0;i<size;i++){
                    auto [distu,u]=q.front();
                   
                    q.pop();
                    for(auto e:g[u]){
                        if(dist[e.first]>distu+e.second){
                            dist[e.first]=distu+e.second;
                            q.push({dist[e.first],e.first});
                        }
                    }
                }
                count++;
                
            }
            return dist[dst]==INT_MAX?-1:dist[dst];

        };
        return bfs();



    }
};