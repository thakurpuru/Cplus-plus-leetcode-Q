class Solution {
public:
    // int count;
    // void solve(string s,int n,int i,string s1){
    //     if(n==s1.size()){
    //         count++;
    //         return;
    //     }
    //     for(int j=i;j<s.size();j++){
    //         solve(s,n,j,s1+s[j]);
    //     }
    // }
    int countVowelStrings(int n) {
       int a=1,e=1,o=1,i=1,u=1;
       
       while(n>1){
            a=(a+e+i+o+u);
            e=(e+i+o+u);
            i=(i+o+u);
            o=(o+u);
            u=u;
            n--;
       }
        return a+i+o+u+e;
    }
};