class Solution {
public:

    // int solve(vector<int>& arr, int difference,int i){
    //     if(i==arr.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int count=1;
    //     for(int j=i+1;j<arr.size();j++){
            
    //         if(arr[j]-arr[i]==difference){
    //             count=max(count,1+solve(arr,difference,j));
    //         }
    //     }
        
    //     return dp[i]=count;
    // }
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int> dp;
        // sort(arr.begin(),arr.end());
        int res=0;
        for(int i=0;i<n;i++){
            dp[arr[i]]=dp[arr[i]-difference]+1;
            res=max(res,dp[arr[i]]);
        }
        return res;
    }
};