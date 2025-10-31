class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        vector<long long> sqr(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            sqr[i]=(nums[i]*nums[i]);
        }
        sort(sqr.begin(),sqr.end(),std::greater<long long>());
        int n=sqr.size();
        if(n%2==0){
            n=n/2;
            n=n-1;
        }else{
            n=n/2;
        }
        long long sum=0;
        for(int i=0;i<=n;i++){
            sum+=sqr[i];
        }
        long long diff=0;
        for(int i=n+1;i<sqr.size();i++){
            diff+=sqr[i];
        }
        return sum-diff;
    }
};