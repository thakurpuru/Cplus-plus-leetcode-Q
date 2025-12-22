class Solution {
public:
    
    int minDeletionSize(vector<string>& strs) {
        int len=strs[0].size();
        int n=strs.size();
        int count=0;
        for(int i=0;i<len;i++){

            for(int j=1;j<n;j++){
                if(strs[j-1][i]>strs[j][i]){
                    count++;
                    break;
                }

            
            }
        }
        return count;
    }
};