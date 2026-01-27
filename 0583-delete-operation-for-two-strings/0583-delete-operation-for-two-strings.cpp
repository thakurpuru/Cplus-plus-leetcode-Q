class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> get=[&](int i,int j){
            if(i>=n || j>=m) return 0;
            if(dp[i][j]!=-1) return dp[i][j];
            if(word1[i]==word2[j]){
                return dp[i][j]=1+get(i+1,j+1);
            }
            return dp[i][j]=max(get(i+1,j),get(i,j+1));          
        };
        int a=get(0,0);
        return n-a+m-a;
    }
};