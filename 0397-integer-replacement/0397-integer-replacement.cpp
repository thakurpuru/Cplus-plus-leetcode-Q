class Solution {
public:
    int integerReplacement(int n) {
        long long m=n;
        int count1=0;
        while(m!=1){
            if(m%2==0){
                m/=2;
            }else{
                if(m==3 || (m&2)==0){
                    m=m-1;

                }else{
                    m+=1;
                }
            }
            count1++;

        }
       
        return count1;
    }
};