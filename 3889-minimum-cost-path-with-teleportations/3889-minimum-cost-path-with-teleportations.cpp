class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(m,vector<int>(n,INT_MAX)));
        const int INF = 1e9;
        const int MAX_VAL = 10000;

        vector<vector<pair<int, int>>> val_to_coords(MAX_VAL + 1);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    val_to_coords[grid[i][j]].push_back({i, j});
                }
            }
        dp[0][0][0]=0;
        for(int t=0;t<=k;t++){
             priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(dp[t][i][j]!=INT_MAX){
                        q.push({dp[t][i][j],{i,j}});
                    }
                }
            }

            while(!q.empty()){
                auto [w,rest]=q.top();
                auto [i,j]=rest;

                q.pop();
                if (w > dp[t][i][j]) continue;
                if(i+1<m && dp[t][i+1][j]>w+grid[i+1][j]){
                    dp[t][i+1][j]=w+grid[i+1][j];
                    q.push({dp[t][i+1][j],{i+1,j}});
                }
                if(j+1<n && dp[t][i][j+1]>grid[i][j+1]+w){
                    dp[t][i][j+1]=w+grid[i][j+1];
                    q.push({dp[t][i][j+1],{i,j+1}});
                }
            }

            if (t < k) {
                vector<int> min_cost_at_val(MAX_VAL + 1, INF);
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        min_cost_at_val[grid[i][j]] =
                            min(min_cost_at_val[grid[i][j]], dp[t][i][j]);
                    }
                }

                vector<int> suffix_min(MAX_VAL + 2, INF);
                for (int v = MAX_VAL; v >= 0; --v) {
                    suffix_min[v] = min(suffix_min[v + 1], min_cost_at_val[v]);
                }

                for (int v = 0; v <= MAX_VAL; ++v) {
                    if (suffix_min[v] == INF) continue;
                    for (auto& [r, c] : val_to_coords[v]) {
                        dp[t + 1][r][c] =
                            min(dp[t + 1][r][c], suffix_min[v]);
                    }
                }
            }
        }
       
      
        int ans = INF;
        for (int t = 0; t <= k; ++t) {
            ans = min(ans, dp[t][m - 1][n - 1]);
        }        
        return ans >= INF ? -1 : ans;
    }
};