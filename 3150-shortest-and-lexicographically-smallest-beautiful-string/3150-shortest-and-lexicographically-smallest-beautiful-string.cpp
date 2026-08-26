class Solution {
public:
    bool check(string str,string s,int i){
        int k=0;
        while(k<str.size() && s[i]==str[k]){
            i++;
            k++;
        }
        if(k==str.size()) return false;
        return s[i]<str[k];
    }
    string shortestBeautifulSubstring(string s, int k) {
        int len=INT_MAX;
        string str="";
        int j=0,cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
            while(j<n && cnt>k){
                if(s[j]=='1')cnt--;
                j++;
            }
            while(j<n && s[j]=='0')j++;
            if(cnt==k && len>i-j+1){
                len=i-j+1;
                str=s.substr(j,len);
            }
            if(cnt==k && len==i-j+1 && check(str,s,j)){
                str=s.substr(j,len);
            }
        }
        return str;
    }
};