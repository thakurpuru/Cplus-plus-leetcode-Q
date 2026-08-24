class Solution {
public:
    int solve(vector<int>& stones,int st,int turn,vector<int>& prefix){
        int n=stones.size();
        if(st==n-1) return 0;
        int bob=0,alice=0;
        int ans=INT_MIN;
        for(int i=st+2;i<=n;i++){
            
            if(turn){
                alice=prefix[i]+solve(stones,i-1,turn^1,prefix);
            }else{
                bob=prefix[i]+solve(stones,i-1,turn^1,prefix);
            }
        }
        ans=max(ans,alice-bob);
        return ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> prefix(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=stones[i];
            prefix[i]=sum;
        }
        int ans=prefix[n-1];
        for(int i=n-2;i>0;i--){
            ans=max(ans,prefix[i]-ans);
        }
        return ans;
    }
};