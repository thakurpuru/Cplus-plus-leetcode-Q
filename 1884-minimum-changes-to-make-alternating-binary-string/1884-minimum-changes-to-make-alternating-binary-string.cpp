class Solution {
public:
    int minOperations(string s) {
        int bit=0;
        int count1=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'0';
            if(ch^bit==1) count1++;
            bit^=1;
        }
        bit=1;
        int count2=0;
        for(int i=0;i<s.size();i++){
            int ch=s[i]-'0';
            if(ch^bit==1) count2++;
            bit^=1;
        }
        cout<<count1<<count2;
        return min(count1,count2);
    }
};