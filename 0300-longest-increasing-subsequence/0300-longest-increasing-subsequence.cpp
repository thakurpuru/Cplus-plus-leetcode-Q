class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,1);
        int answer=1;
        for(int i=1;i<n;i++){
            for(int l=0;l<i;l++){
                if(nums[l]<nums[i]){
                    if(vec[l]+1>vec[i]){
                        vec[i]=vec[l]+1;
                    }
                }
            }
            answer=max(answer,vec[i]);
        }
        return answer;

    }
};