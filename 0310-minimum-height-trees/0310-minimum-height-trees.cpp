class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n);
        vector<vector<int>> graph(n);
        vector<int>degree(n,0);
        vector<int> ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }


        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int> q;
        function<void()> bfs=[&](){
            
            while(q.size()>0){
                int size=q.size();
                ans.clear();
                for(int i=0;i<size;i++){
                    int neighbour=q.front();
                    ans.push_back(neighbour);
                    q.pop();
                    for(auto v:graph[neighbour]){
                        degree[v]--;
                        if(degree[v]==1){
                            q.push(v);
                        }
                    }
                }
            }
            

        };
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }
        bfs();
        return ans;
    }
};