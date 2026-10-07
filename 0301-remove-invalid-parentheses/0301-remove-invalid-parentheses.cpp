class Solution {
public:
    bool valid(string s){
        int balance=0;
        for(char c:s){
            
            if(c=='('){
                balance++;
            }else if(c==')'){
                balance--;
                if(balance<0) return false;
            }
        }
        return balance==0;
    }
    int mn;
    unordered_set<string> st;
    void solve(string& s,string& t,int count,int i){
        if(i>=s.size()){
            if(valid(t)){
                if(count<mn){
                    mn=count;
                    st.clear();
                }
                if(count==mn)
                st.insert(t);
            }
            return ;
        }
        t.push_back(s[i]);
        solve(s,t,count,i+1);
        t.pop_back();
        if(s[i]=='(' || s[i]==')')
        solve(s,t,count+1,i+1);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        mn=INT_MAX;
        string t="";
        solve(s,t,0,0);
        vector<string> vec(st.begin(),st.end());
        return vec;
    }
};