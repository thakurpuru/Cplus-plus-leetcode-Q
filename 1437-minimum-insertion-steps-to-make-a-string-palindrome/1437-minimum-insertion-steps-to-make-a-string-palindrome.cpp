class Solution {
public:
    vector<vector<int>> dp;
    int sequence(string &st,int i,int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(st[i]==st[j]){
            return dp[i][j]=2+sequence(st,i+1,j-1);
        }
        return dp[i][j]=max(sequence(st,i+1,j),sequence(st,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.size();
        dp.assign(n,vector<int>(n,-1));
        
        return n-sequence(s,0,n-1);
    }
};