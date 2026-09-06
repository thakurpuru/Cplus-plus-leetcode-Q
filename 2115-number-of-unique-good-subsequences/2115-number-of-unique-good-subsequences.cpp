class Solution {
public:
    int mod=1e9+7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int zero=0;
        long long dp0=0,dp1=0;
        
        for(char c: binary){
            if(c=='0'){
                dp0=(dp0+dp1)%mod;
                zero=1;   
            }else{
                dp1=(dp1+dp0+1)%mod;
            }
        }
        
        return (dp0+dp1+zero)%mod;
    }
};