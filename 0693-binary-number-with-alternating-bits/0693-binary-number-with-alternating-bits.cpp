class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit=n%2;
        
        while(n>0){
            if((n&1)^bit) return false;
            n=n>>1;
            bit^=1;
        }
        return true;
    }
};