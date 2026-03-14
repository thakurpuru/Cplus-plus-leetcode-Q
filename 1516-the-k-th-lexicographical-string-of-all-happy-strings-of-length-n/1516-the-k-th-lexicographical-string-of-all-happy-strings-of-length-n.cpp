class Solution {
public:
    string ans;
    void solve(int n,string s,string &st,int &k){
        if(s.size()==n){
            k--;
            if(k==0) ans=s;
            return;
        }
        for(int i=0;i<3;i++){
            int j=s.size();
            if(s.empty() || s.back()!=st[i]){
                solve(n,s+st[i],st,k);
            }
        }
    }
    string getHappyString(int n, int k) {
        ans="";
        string s="abc";
        solve(n,"",s,k);
        return ans;
    }
};