class Solution {
public:
    vector<int> sumZero(int n) {
       vector<int> ans;
       int i=1;
       while(n>0){
            if(n>=2){
                ans.push_back(i);
                ans.push_back(-i);
                i++;
                n-=2;
            }else if(n==1){
                ans.push_back(0);
                n--;
            }
       } 
       return ans;
    }
};