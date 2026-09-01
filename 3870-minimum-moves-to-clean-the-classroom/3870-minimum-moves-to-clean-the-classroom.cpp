class Solution {
public:
   
    int minMoves(vector<string>& classroom, int energy) {
        int m=classroom.size(),n=classroom[0].size();
        int cnt=0;
        using T=tuple<int,int,int,int,int>;
        queue<T> q;
        vector<vector<int>> id(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(classroom[i][j]=='S'){
                    q.push({i,j,energy,0,0});
                }
                if(classroom[i][j]=='L') id[i][j]=cnt++;
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int fullmask=(1<<cnt)-1;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(1<<cnt,-1)));

        while(!q.empty()){
            int sz=q.size();
            
            auto [i,j,e,mask,step]=q.front();
            q.pop();
            if(mask==fullmask) return step;
            if(e<=0) continue;
            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && e>0 && classroom[x][y]!='X'){
                    int ne=e-1;
                    int nmask=mask;
                    if(classroom[x][y]=='R'){
                        ne=energy;
                    }
                    if(classroom[x][y]=='L'){
                        nmask=nmask | (1<<id[x][y]);
                    }
                    if(ne<=dp[x][y][mask]) continue;
                    dp[x][y][mask]=ne;
                    q.push({x,y,ne,nmask,step+1});
                }
            
            }
        }
        return -1;
    }
};