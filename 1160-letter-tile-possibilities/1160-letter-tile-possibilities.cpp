class Solution {
public:
    int count;
    set<string> st;
    void solve(string &s,vector<bool> &used,string s1){
        

        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1] && !used[i-1]) continue;
            if(!used[i]){
                used[i]=true;
                count++;
                solve(s,used,s1);
                
                used[i]=false;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        count=0;
        int n=tiles.size();
        vector<bool> used(n,false);
        sort(tiles.begin(),tiles.end());
        solve(tiles,used,"");
        return count;
    }
};