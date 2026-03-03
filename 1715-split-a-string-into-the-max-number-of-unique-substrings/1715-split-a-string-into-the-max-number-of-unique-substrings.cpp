class Solution {
public:
    int ans=1;
    void solve(string s,int start,unordered_set<string> &st){
        if(start>=s.size()){
            ans=max(ans,(int)st.size());
            return;
        } 
        

        for(int i=start;i<s.size();i++){
            string sub=s.substr(start,i-start+1);
            if(!st.count(sub)){
                st.insert(sub);
                solve(s,i+1,st);
                st.erase(sub);
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        solve(s,0,st);
        return ans;
    }
};