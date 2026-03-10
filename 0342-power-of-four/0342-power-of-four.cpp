class Solution {
public:
    bool isPowerOfFour(int a) {
        long long n=a;
        
        return (n&(n-1))==0 && n%3==1;
    }
};