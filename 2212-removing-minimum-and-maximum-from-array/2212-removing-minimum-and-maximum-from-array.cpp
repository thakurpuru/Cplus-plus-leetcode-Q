class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        int i=0,j=0;
        int n=nums.size();
        for(int k=0;k<n;k++){
            if(mn>nums[k]){
                mn=nums[k];
                i=k;
            }
            if(mx<nums[k]){
                mx=nums[k];
                j=k;
            }
        }
        int ans=(i<j)?(i+1)+(n-j):(j+1)+(n-i);
        return min({max(n-i,n-j),max(i+1,j+1),ans});
    }
};