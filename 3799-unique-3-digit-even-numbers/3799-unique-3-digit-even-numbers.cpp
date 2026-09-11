class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int even=0,zero=0;
        vector<int> vec(10,0);
        for(int i=0;i<n;i++){
            vec[digits[i]]++;
        }
        int ans=0;
        for(int i=1;i<10;i++){
            if(vec[i]==0) continue;
            vec[i]--;
            for(int j=0;j<10;j++){
                if(vec[j]==0) continue;
                vec[j]--;
                for(int u=0;u<=8;u+=2){
                    if(vec[u]>0){
                        ans++;
                    }
                    
                }
                vec[j]++;
            }
            vec[i]++;
        }
        return ans;
    }
};