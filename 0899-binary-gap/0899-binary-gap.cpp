class Solution {
public:
    int binaryGap(int n) {
        if(n&(n-1)==0) return 0;
        string s="";
        while(n>0){
            s=to_string(n&1)+s;
            n=n>>1;
        }
        cout<<s;
        int j=1, i=0;
        // while(j>s.size() && s[j]=='0') j++;
        // i=j;
        int ans=0;
        while(j<s.size()){
            if(s[j]=='1'){
                ans=max(ans,j-i);
                i=j;
            }
            j++;
        }
        return ans;

    }
};