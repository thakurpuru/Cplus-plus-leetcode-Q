class Solution {
public:
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>& q,int &fresh){
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty() && fresh>0){
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++){
                auto [x,y]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int i=x+dx[k],j=y+dy[k];
                    if(i>=0 && j>=0 && i<m && j<n && grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j]=2;
                        fresh--;
                    }
                }
            }
        }
        return ans;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int ans=bfs(grid,q,fresh);
        return fresh==0?ans:-1;
    }
};