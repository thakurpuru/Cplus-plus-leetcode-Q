class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>prefix(n,0),sufix(n,0);
        int count_b=0;
        for(int i=0;i<n;i++){
            prefix[i]=count_b;
            if(s[i]=='b'){
                count_b++;
            }
        }
        int count_a=0;
        for(int i=n-1;i>=0;i--){
            sufix[i]=count_a;
            if(s[i]=='a'){
                count_a++;
            }
        }
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            ans=min(ans,prefix[i]+sufix[i]);
        }
        return ans;

    }
};