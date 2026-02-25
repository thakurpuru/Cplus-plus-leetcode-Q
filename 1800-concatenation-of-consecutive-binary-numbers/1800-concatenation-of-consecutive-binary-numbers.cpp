class Solution {
public:
    int mod=1e9+7;
    int concatenatedBinary(int n) {
        long long ans=0;
        int len=0;
        int i=1;
        while(i<=n){
            
            if((i&(i-1))==0) len++;
            
            ans=(ans<<len)|i;
            ans=ans%mod;
            i++;
        }
        return ans%mod;
    }
};