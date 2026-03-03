class Solution {
public:
    string invert(string s){
        string s1="";
        for(char c:s){
            if(c=='0'){
                s1+='1';
            }else{
                s1+='0';
            }
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
    char findKthBit(int n, int k) {
        string s1="0";
        for(int i=2;i<=n;i++){
            s1=s1+'1'+ invert(s1);
        }
        return s1[k-1];
    }
};