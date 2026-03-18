class Solution {
public:
    vector<int> evenOddBit(int n) {
        int count=0,a=0,b=0;
        while(n>0){
            if((n&1)){
                count%2==0?a++:b++;
            }
            count++;
            n>>=1;

        }
        return {a,b};
    }
};