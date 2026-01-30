class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        function<int(int,int)> subsequence=[&](int i,int j){
            if(j>=m) return 1;
            if(i>=n) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            int ans=0;
            
            if(s[i]==t[j]){
                
                ans+=subsequence(i+1,j+1);
                
            }
            ans+=subsequence(i+1,j);
            return dp[i][j]=ans;

        };
        
        return subsequence(0,0);
        
    }
};