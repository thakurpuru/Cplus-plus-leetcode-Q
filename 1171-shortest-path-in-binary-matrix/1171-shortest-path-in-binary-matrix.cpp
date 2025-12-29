class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        function<int(int,int)> bfs=[&](int i,int j){
            q.push({i,j});
             int dx[8] = {1,1,1,0,0,-1,-1,-1};
            int dy[8] = {1,0,-1,1,-1,1,0,-1};
            dp[0][0]=1;
            while(q.size()>0){
                auto [x,y]=q.front();
                if(x==n-1 && y==n-1) return dp[x][y];
                q.pop();
                for(int i=0;i<8;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<n && nx>=0 && ny<n && ny>=0 && grid[nx][ny]==0 && dp[nx][ny]==-1){
                        dp[nx][ny]=dp[x][y]+1;
                        q.push({nx,ny});
                    }
                }
                
            }
            return -1;

        };
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        return bfs(0,0);
    }
};