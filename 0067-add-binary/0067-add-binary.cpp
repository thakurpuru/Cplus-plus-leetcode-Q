class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size(),j=b.size();
        while(i!=j){
            if(i>j){
                b='0'+b;
                j++;
            }else{
                a='0'+a;
                i++;
            }
        }
        int carry=0;
        i=a.size()-1;
        while(i>=0){
            int bit1=a[i]-'0';
            int bit2=b[i]-'0';
            int total=bit1+bit2+carry;
            ans=to_string((total%2))+ans;
            carry=total/2;
            i--;
        }
        if(carry==1){
            ans='1'+ans;
        }
        return ans;
    }
};