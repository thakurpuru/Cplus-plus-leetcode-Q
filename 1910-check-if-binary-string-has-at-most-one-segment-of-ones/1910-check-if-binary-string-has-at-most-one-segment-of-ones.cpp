class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s[0]=='0') return false;
        bool a=false,b=false;
        int i=0;
        while(i<s.size() && s[i]=='1') i++;
        while(i<s.size() && s[i]=='0') i++;
        return i==s.size();

        
    }
};