class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int i=0,j=0;
        int ans=0;
        while(i<s.size()){
            if(!st.count(s[i])){
                st.insert(s[i]);
            }else{
                while(st.count(s[i])){
                    st.erase(s[j]);
                    j++;
                }
                st.insert(s[i]);

            }
            ans=max(ans,(int)st.size());
            i++;
        }
        return ans;
    }
};