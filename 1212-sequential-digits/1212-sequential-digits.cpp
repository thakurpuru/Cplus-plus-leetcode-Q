class Solution {
public:
    
    void solve(long long num,int low,int high,int j,vector<int>& ans){
        if(num>=low && num<=high){
            ans.push_back(num);
        }
        if(num>high || j>9){
            return;
        }
       
            
        solve(num*10+j,low,high,j+1,ans);
        
        return;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(long long i=1;i<=9;i++){
            solve(i,low,high,i+1,ans);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};