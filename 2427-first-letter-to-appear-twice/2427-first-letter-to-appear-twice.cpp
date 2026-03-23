class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> st(26,false);
        for(char c:s){
            int a=c-'a';
            if(st[a])return c;
            st[a]=true;
        }
        return 'a';
    }
};