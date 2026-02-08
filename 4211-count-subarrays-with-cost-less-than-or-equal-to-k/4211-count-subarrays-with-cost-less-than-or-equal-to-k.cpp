class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        deque<int> maxq,minq;
        long long ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            
            while(!maxq.empty() && nums[maxq.back()]<=nums[i])
                maxq.pop_back();
            maxq.push_back(i);
            while(!minq.empty() && nums[minq.back()]>=nums[i])
                minq.pop_back();
            minq.push_back(i);
            while((long long)(nums[maxq.front()] - nums[minq.front()]) * (i - j + 1) > k){
                if(maxq.front()==j) maxq.pop_front();
                if(minq.front()==j) minq.pop_front();
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};