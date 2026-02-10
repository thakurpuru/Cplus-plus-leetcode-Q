class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        unordered_set<int> even,odd;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }else{
                    odd.insert(nums[j]);
                }
                if(even.size()==odd.size()){
                    ans=max(ans,j-i+1);
                }
            }
            even.clear();
            odd.clear();
        }
        return ans;
    }
};