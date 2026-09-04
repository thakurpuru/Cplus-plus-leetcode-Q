class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int j=0,n=nums1.size();
        int cnt=0,omin=INT_MAX,emin=INT_MAX;
        for(int k=0;k<n;k++){
            if(nums1[k]%2!=0){
                cnt++;
                omin=min(omin,nums1[k]);
            }else{
                emin=min(emin,nums1[k]);
            }
            
        }
        if(cnt==0 || cnt==n) return true;
        if(emin-omin>=1) return true;
        return false;

    }
};