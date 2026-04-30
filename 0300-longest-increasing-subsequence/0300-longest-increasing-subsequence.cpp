class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,1);
        int answer=1;
        for(int i=1;i<n;i++){
           int j=0;
           while(j!=i){
                if(nums[j]<nums[i]){
                    vec[i]=max(vec[j]+1,vec[i]);
                }
                j++;
           }
           answer=max(answer,vec[i]);
        }
        return answer;

    }
};