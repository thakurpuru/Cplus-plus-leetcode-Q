class Solution {
public:
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> vec(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i][j]=matrix[i][j]-'0';
            }
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(vec[i][j]==1){
                    vec[i][j]+=vec[i][j-1];
                    
                }
            }
        }
        int ans=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                int width=vec[i][j];
                if(width==0) continue;
                int currwidth=width;
                for(int k=i;k<m && vec[k][j]>0;k++){
                    currwidth=min(currwidth,vec[k][j]);
                    int h=k-i+1;
                    ans=max(ans,currwidth*h);
                }
                currwidth=width;
                for(int k=i;k>=0 && vec[k][j]>0;k--){
                    currwidth=min(currwidth,vec[k][j]);
                    int h=i-k+1;
                    ans=max(ans,currwidth*h);
                }

            }
        }
        return ans;
    }
};