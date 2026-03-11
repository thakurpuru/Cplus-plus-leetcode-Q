class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int i=log2(n)+1;
        return n^((1<<i)-1);
    }
};