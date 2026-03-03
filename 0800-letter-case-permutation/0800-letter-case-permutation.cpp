class Solution {
public:
    vector<string> ans;
    void solve(string s,int i,string s1){
        if(s.size()==s1.size()){
            ans.push_back(s1);
            return;
        }
        solve(s,i+1,s1+s[i]);
        if(isalpha(s[i])){
            if(isupper(s[i])){
                solve(s,i+1,s1+(char)tolower(s[i]));
            }else{
                solve(s,i+1,s1+(char)toupper(s[i]));
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(s,0,"");
        return ans;
    }
};