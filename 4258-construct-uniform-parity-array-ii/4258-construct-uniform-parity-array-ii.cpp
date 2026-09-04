class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int j=0,n=nums1.size();
        int cnt=0;
        for(int k=0;k<n;k++){
            if(nums1[k]%2!=0){
                cnt++;
                if(nums1[k]<nums1[j]) j=k;
            }
            
        }
        if(cnt==0 || cnt==n) return true;
        int l=0;
        while(l<n){
            if(nums1[l]%2==0 && nums1[l]-nums1[j]<1) return false;
            l++;
        }
        return true;

    }
};