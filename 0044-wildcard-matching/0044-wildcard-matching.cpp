class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    bool sequence(string &s,string &p,int i,int j){
        if(i==n && j==m )return true;
        if(i==n){
            while(j<m){
                if(p[j]!='*') return false;
                j++;
            }
            return true;
        }
        if(j==m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(s[i]==p[j] || p[j]=='?'){
            ans=sequence(s,p,i+1,j+1);
        }else if(p[j]=='*'){
            ans=sequence(s,p,i,j+1) || sequence(s,p,i+1,j);
        }

        return dp[i][j]=ans;
        
    }
    bool isMatch(string s, string p) {
        n=s.size();m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return sequence(s,p,0,0);
        
    }
};