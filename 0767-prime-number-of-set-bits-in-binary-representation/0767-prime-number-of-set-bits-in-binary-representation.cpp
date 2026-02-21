class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int a=__builtin_popcount(i);
            bool prime=true;
            for(int j=2;j*j<=a;j++){
                if(a%j==0){
                    prime=false;
                    break;
                }
            }
            if(a!=1 && prime) ans++;
        }
        return ans;
    }
};