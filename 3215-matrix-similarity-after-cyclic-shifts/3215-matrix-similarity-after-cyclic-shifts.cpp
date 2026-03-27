class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> vec=mat;
        int m=mat.size();
        int n=mat[0].size();
        for(int l=0;l<k;l++){
            for(int i=0;i<m;i++){
                if(i%2==0){
                    int temp=mat[i][0];
                    for(int j=1;j<n;j++){
                        mat[i][j-1]=mat[i][j];
                    }
                    mat[i][n-1]=temp;
                }else{
                    int t=mat[i][n-1];
                    for(int j=n-1;j>0;j--){
                        mat[i][j]=mat[i][j-1];
                    }
                    mat[i][0]=t;
                }
            }
        }
        return vec==mat;
    }
};