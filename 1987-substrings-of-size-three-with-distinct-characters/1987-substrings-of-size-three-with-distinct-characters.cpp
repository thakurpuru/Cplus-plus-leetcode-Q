class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.size();
        if(n<3) return 0;
        int j=0,count=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(i>2){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    mp.erase(s[j]);
                }
                j++;
            }
            
            mp[s[i]]++;
            if(mp.size()==3)count++;
        }
        return count;
    }
};