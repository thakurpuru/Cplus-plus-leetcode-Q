class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        // function<int(int,int)> subsequence=[&](int i,int j){
        //     if(i>=text1.size() || j>=text2.size()) return 0;
        //     int ans=0;
        //     if(dp[i][j]!=-1) return dp[i][j];
        //     if(text1[i]==text2[j]){
        //         ans=1+subsequence(i+1,j+1);
        //     }else{
        //         ans=max(ans,max(subsequence(i+1,j),subsequence(i,j+1)));
        //     }
        //     return dp[i][j]=ans;
        // };
        // return subsequence(0,0);
        int n=text1.size(),m=text2.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};