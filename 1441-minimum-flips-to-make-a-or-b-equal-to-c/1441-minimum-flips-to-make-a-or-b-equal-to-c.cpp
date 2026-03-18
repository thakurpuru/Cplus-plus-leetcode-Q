class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        int n=max(a,max(b,c));
        while(n>0){
            if((c&1) && !(b&1) && !(a&1)){
                count++;
            }else if(!(c&1)){
                if((b&1) && (a&1)){
                    count+=2;
                }else if((b&1) || (a&1)){
                    count++;
                }
            }
            n>>=1;b>>=1;c>>=1;a>>=1;
        }
        return count;
    }
};