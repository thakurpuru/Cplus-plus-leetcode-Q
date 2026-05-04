class Solution {
public:
    int count;
    unordered_map<string,char> mp;
    vector<int> dp;
    int solve(string& s,int i){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        if(i+1<s.size() && mp.count(s.substr(i,2))){
            ways+=solve(s,i+2);
        }
        if(mp.count(s.substr(i,1)))
        ways+=solve(s,i+1);
        return dp[i]=ways;
    } 
    int numDecodings(string s) {
        for(int i=1;i<=26;i++){
            mp[to_string(i)]='A'+i;
        }
        dp.assign(s.size(),-1);
        return solve(s,0);
    }
};