class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> max_q;
        for(int i=0;i<nums.size();i++){
            
            while(!max_q.empty()>0 && max_q.front()<i-k+1) max_q.pop_front();
            while(!max_q.empty() && nums[i]>=nums[max_q.back()]){
                max_q.pop_back();
            }
            max_q.push_back(i);
            
            if(i>=k-1)
            ans.push_back(nums[max_q.front()]);
        }
        return ans;
    }
};