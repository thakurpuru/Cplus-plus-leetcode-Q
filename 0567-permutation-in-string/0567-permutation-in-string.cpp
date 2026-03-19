class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp1,mp2;
        for(char c:s1)mp1[c]++;
        int n=s1.size();
        int j=0;
        for(int i=0;i<s2.size();i++){
            if(mp1.count(s2[i])){
                mp2[s2[i]]++;
            }else{
                mp2.clear();
                j=i;
            }
            if(i-j+1==n){
                if(mp1==mp2) return true;
                if(mp2.count(s2[j])){
                    mp2[s2[j]]--;
                    if(mp2[s2[j]]==0){
                        mp2.erase(s2[j]);
                    }
                }
                j++;
            }


        }
        return false;
    }
};