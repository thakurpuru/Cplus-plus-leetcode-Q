class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st;
        
        int j=0;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.back().first==s[i]){
                st.back().second++;
            }else{
                st.push_back({s[i],1});
            }
            if(st.back().second==k) st.pop_back();

        }
        string ans="";
        for(auto p:st){
            ans+=string(p.second,p.first);
        }
        return ans;
    }
};