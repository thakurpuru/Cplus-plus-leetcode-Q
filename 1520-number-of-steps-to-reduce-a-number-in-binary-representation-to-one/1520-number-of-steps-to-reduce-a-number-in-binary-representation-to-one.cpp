class Solution {
public:
    int numSteps(string s) {
        long long n=0;
        long long count=0;
        string s1=s;
        int i=s.size()-1;
        while(i>0){
            if(s1[i]=='0'){
                i--;
                count++;
            }else{
                int a=0;
                while(i>=0 && s1[i]=='1'){
                    i--;
                    a++;
                }
                count+=(a+1);
                if(i<0) return count;
                s1=s1.substr(0,i);
                s1=s1+'1';
                i=s1.size()-1;
            }
            
        }
       
        return count;
    }
};