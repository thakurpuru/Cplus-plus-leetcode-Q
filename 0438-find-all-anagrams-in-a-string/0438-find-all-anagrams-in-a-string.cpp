class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(),j=0,count=0;
        vector<int> res;
        unordered_map<char,int> pw,sw;
        for(char c:p) pw[c]++;
        for(int i=0;i<n;i++){
            if(pw.count(s[i])){
                sw[s[i]]++;
            }else{
                j=i;
                sw.clear();
            }
            if(i-j+1==p.size()){
                if(sw==pw)res.push_back(j);
                if(sw.count(s[j])){
                    sw[s[j]]--;
                    if(sw[s[j]]==0){
                        sw.erase(s[j]);
                    }
                }
                j++;
            }

        }
        return res;

    }
};