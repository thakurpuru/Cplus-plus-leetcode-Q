class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int subsequence(string &s1,string &s2,int i,int j){
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=subsequence(s1,s2,i+1,j+1);
        }
        return dp[i][j]=1+min({subsequence(s1,s2,i+1,j+1),subsequence(s1,s2,i,j+1),subsequence(s1,s2,i+1,j)}) ;
    }
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
        if(n==0) return m;
        dp.assign(n,vector<int>(m,INT_MAX));
        int ans=subsequence(word1,word2,0,0);
        // if(n==m && ans==m) return 0;
        // if(n==m) return ans;
        return ans;
    }
};