class Solution {
public:
    string backtrack(vector<int>& freq,string target,int i){
        int n=target.size();
        if(i==n) return "";
        int x=target[i]-'a';
        if(freq[x]>0){
            freq[x]--;
            string res=backtrack(freq,target,i+1);
            if(res!=""){
                return target[i]+res;
            }
            freq[x]++;
        }

        for(int i=x+1;i<26;i++){
            if(freq[i]>0){
                freq[i]--;
                string ans="";
                ans+=(i+'a');
                for(int i=0;i<26;i++){
                    if(freq[i]>0){
                        ans+=string(freq[i],i+'a');
                    }
                }
                return ans;
            }
        }
        return "";
    }
    string lexGreaterPermutation(string s, string target) {
        if(s=="") return "";
       
        vector<int> freq(26,0);
        for(char c:s) freq[c-'a']++;
        
        return backtrack(freq,target,0);
    }
};