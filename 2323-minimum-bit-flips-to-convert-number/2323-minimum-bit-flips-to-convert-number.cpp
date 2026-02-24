class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0;
        int x=start^goal;
        while(x>0){
            count+=(x&1);
            x>>=1;
        }   
        
        return count;
    }
};