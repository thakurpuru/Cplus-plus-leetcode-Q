constexpr int N=1<<20;
class Solution {
public:
    bitset<N> bs;
    bool hasAllCodes(string s, int k) {
        if(k>s.size()) return false;
        int mask=0;
        int M=(1<<(k-1))-1;
        for(int i=0;i<k;i++){
            mask=(mask<<1)|(s[i]-'0');
        }
        bs[mask]=1;
        for(int i=k;i<s.size();i++){
            mask&=M;
            mask<<=1;
            mask|=s[i]-'0';
            bs[mask]=1;
        }
        return bs.count()==1<<k;

    }
};