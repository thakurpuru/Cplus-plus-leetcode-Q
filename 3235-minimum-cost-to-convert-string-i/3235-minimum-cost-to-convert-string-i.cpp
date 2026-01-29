class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
       unordered_map<char,vector<pair<char,int>>> graph;
       int m=original.size();
       for(int i=0;i<m;i++){
            graph[original[i]].push_back({changed[i],cost[i]});
       }
       long long ans=0;
       int i=0,n=target.size();
       vector<vector<long long>> dp(26,vector<long long>(26,-1));
       function<long long(char,char)> bfs=[&](char s,char d) -> long long{
            long long INF=1e18;
            vector<long long> dist(26,INF);
            priority_queue<pair<long long,char>,vector<pair<long long,char>>,greater<>> q;
            int node=s-'a';
            int sr=d-'a';
            if(dp[node][sr]!=-1) return dp[node][sr];
            dist[node]=0;
            q.push({0,s});
            while(!q.empty()){
                auto [w,ch]=q.top();
                q.pop();
                int u=ch-'a';
                if(w>dist[u]) continue;
                for(auto [v,wt]:graph[ch]){
                    int v_idx = v - 'a';
                    if(dist[v_idx]>dist[u]+wt){
                        dist[v_idx]=dist[u]+wt;
                        q.push({dist[v_idx],v});
                    }
                }
            }
            if(dist[sr]==INF) return -1;
            return dp[node][sr]=dist[sr];

       };



       while(i<n){
            if(source[i]==target[i]){
                i++;
            }else if(graph.count(source[i])){
                int cost=bfs(source[i],target[i]);
                if(cost==-1) return -1;
                ans+=cost; 
                i++;
            }else{
                return -1;
            }
       }
       return ans;
    }
};