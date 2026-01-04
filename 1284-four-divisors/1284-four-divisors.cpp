class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            vector<int> divisor;
            for(int j=2;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    divisor.push_back(j);
                    if(nums[i]/j!=j)
                    divisor.push_back(nums[i]/j);
                }
            }
            if(divisor.size()==2){
                ans+=(1+nums[i]+divisor[0]+divisor[1]);
               
            }
        }
        return ans;

    }
};