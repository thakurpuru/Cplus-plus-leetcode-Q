class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        function<int(int,int)> bfs=[&](int i,int j){
            q.push({0,{i,j}});
            dist[i][j]=0;
            while(q.size()>0){
                auto [effort,cell]=q.top();
                auto [x,y]=cell;
                if(x==n-1 && y==m-1) return effort;
                q.pop();
                if (effort > dist[x][y]) continue;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=0 && nx<n && ny<m && ny>=0){
                        int neweffort=max(effort,abs(heights[x][y]-heights[nx][ny]));

                        if(neweffort<dist[nx][ny]){
                            dist[nx][ny]=neweffort;
                            q.push({neweffort,{nx,ny}});
                        }
                    }
                }
            }
            return 0;
        }; 
        
        return bfs(0,0);
    }
};