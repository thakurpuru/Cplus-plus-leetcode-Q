class Solution {
public:
    void backtrack(string& s,int start,unordered_set<string>&st,vector<string>& curr,vector<string>& result, vector<bool>& dp){
        if(start==s.size()){
            string sentence="";
            for(auto& word:curr){
                if(sentence!="") sentence+=" ";
                sentence+=word;
            }
            result.push_back(sentence);
        }
        for(int i=start+1;i<=s.size();i++){
            string word=s.substr(start,i-start);
            if(dp[i] && st.count(word)){
                curr.push_back(word);
                backtrack(s,i,st,curr,result,dp);
                curr.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> result;
        vector<string> curr;
        int n=s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int j=0;
        string str="";
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }

            }
        }
        backtrack(s,0,st,curr,result,dp);
        return result;
    }
};