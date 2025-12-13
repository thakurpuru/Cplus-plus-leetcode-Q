class Solution {
public:
    int count;
    unordered_map<string,char>mp;
    vector<int>dp;
    int dfs(int i,string s){
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        if(i+1<=s.size() && mp.count(s.substr(i,1))){
            ways+=dfs(i+1,s);
        }
        if(i+2<=s.size() && mp.count(s.substr(i,2))){
            ways+=dfs(i+2,s);
        }

       return dp[i]=ways;

    }
    int numDecodings(string s) {
        for (int i = 1; i <= 26; i++) {
            mp[to_string(i)] = 'A' + (i - 1);
        }
        dp.assign(s.size(),-1);
        
        return dfs(0,s);

    }
};