class Solution {
public:
    int minOperations(string s) {
        int bit=0,bit1=1;
        int count1=0;
        int count2=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'0';
            if(ch^bit==1) count1++;
            if(ch^bit1==1) count2++;
            bit1^=1;
            bit^=1;
        }
       
        return min(count1,count2);
    }
};