class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string& s,string& p,int i,int j){
        int n=p.size();
        int m=s.size();
        if(j>=n) return i>=m;
        
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(j+1<n && p[j+1]=='*'){
            if(solve(s,p,i,j+2)) return dp[i][j]=true;
            while(i<m && (p[j]==s[i] || p[j]=='.')){
                if(solve(s,p,i+1,j+2)) return dp[i][j]=true;
                i++;
            }
        }else {
            if(i<m && (p[j]=='.' || p[j]==s[i])){
                if(solve(s,p,i+1,j+1)) return dp[i][j]=true;
            }  
        } 
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=p.size(),m=s.size();
         dp.assign(m+1,vector<int>(n+1,-1));
        return solve(s,p,0,0);
    }
};