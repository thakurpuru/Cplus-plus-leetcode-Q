class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int p=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]>nums[i]){
                p=i+1;
            }else{
                break;
            }
        }
        if(p==-1) return false;
        int q=-1;
        while(p<n-1){
            if(nums[p]>nums[p+1]){
                q=p+1;
            }else{
                break;
            }
            p++;
        }
        if(q==-1 || q==n-1) return false;
        while(q<n-1){
            if(nums[q]>=nums[q+1]) return false;
            q++;
        }
        return true;
    }
};