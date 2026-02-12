class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            int uniq=0,maxfreq=0;
            for(int j=i;j<n;j++){
                int k=s[j]-'a';
                if(freq[k]==0) uniq++;
                freq[k]++;
                if(freq[k]>maxfreq) maxfreq=freq[k];
                int curr=j-i+1;
                if(curr==uniq*maxfreq && curr>ans){
                    ans=curr;
                }
            }
        }
        return ans;
    }
};