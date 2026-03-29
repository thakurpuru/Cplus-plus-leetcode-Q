class Solution {
public:
    string minWindow(string s, string t) {
        int n=t.size();
        if(n>s.size()) return "";
        int st=0;
        vector<int> t_mp(128,0);
        for(char c:t) t_mp[c]++;
        int count=0,j=0,len=INT_MAX;
        for(int i=0;i<s.size();){
            if(t_mp[s[i]]>0){
                n--;
            }
            t_mp[s[i]]--;
            i++;
            
            while(n==0){
                if(i-j<len){
                    len=i-j;
                    st=j;
                }
                t_mp[s[j]]++;
                if(t_mp[s[j]]>0){
                    n++;
                }
                j++;
            }
        }
        return len==INT_MAX?"":s.substr(st,len);
    }
};