class Solution {
public:
    long long removeZeros(long long n) {
        string s="";
        long long ans=0;
        int count=0;
        if (n<0){
            n=-n;
            count=1;
        }
        while(n>0){
            long long k=n%10;
            if(k!=0) s=to_string(k)+s;
            
            n=n/10;
            
        }
        if (s!=""){
            ans=std::stoll(s);
        }
        if(count==1) ans=-ans;
        return ans;
    }
};