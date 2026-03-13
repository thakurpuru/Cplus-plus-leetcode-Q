class Solution {
public:
    int findComplement(int num) {
        long long count=0;
        long long n=num;
        while(num>0){
            count++;
            num>>=1;
        }
        long long r=(long long)(1<<count)-1;
        return (n^r);
    }
};