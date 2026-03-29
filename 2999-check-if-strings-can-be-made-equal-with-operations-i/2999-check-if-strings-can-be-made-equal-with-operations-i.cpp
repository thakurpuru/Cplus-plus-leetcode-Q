class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(i+2<n && s1[i]==s2[i+2] && s1[i+2]==s2[i]){
                    swap(s2[i],s2[i+2]);
                }else{
                    return false;
                }
            }
        }
        return s1==s2;
    }
};