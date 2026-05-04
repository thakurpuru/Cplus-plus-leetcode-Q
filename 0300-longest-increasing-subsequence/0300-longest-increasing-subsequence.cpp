class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ls;
        for(int x:nums){
            auto b=lower_bound(ls.begin(),ls.end(),x);
            if(b==ls.end()){
                ls.push_back(x);
            }else{
                *b=x;
            }
        }
        return (int)ls.size();
    }
};