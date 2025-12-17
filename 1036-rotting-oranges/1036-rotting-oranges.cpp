class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>> q;
        int fresh=0;

        function<void()>bfs=[&](){
            
            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            while(q.size()>0 && fresh >0){
                int size=q.size();
                ans++;
                while(size>0){
                    size--;
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){               
                            q.push({nx,ny});
                            grid[nx][ny]=2;
                            fresh--;
                            
                        }
                    }

                }
                
            }
        };
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2){
                        q.push({i,j});
                    }else if(grid[i][j]==1){
                        fresh++;
                    }
                }
            }
            bfs();
            return fresh==0?ans:-1;
    }
};