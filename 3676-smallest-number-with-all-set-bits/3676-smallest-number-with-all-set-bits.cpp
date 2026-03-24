class Solution {
public:
    int smallestNumber(int n) {
        int a=log2(n)+1;
        return (1<<a)-1;
    }
};