class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<long long,int> freq1,freq2;
        for(int i=0;i<n1;i++){
            for(int j=i+1;j<n1;j++)
            freq1[1LL*nums1[i]*nums1[j]]++;
        }
        for(int i=0;i<n2;i++){
            for(int j=i+1;j<n2;j++)
            freq2[1LL*nums2[i]*nums2[j]]++;
        }
        long  long count=0;
        for(int i=0;i<n2;i++){
            long long num=1LL*nums2[i]*nums2[i];
            if(freq1.count(num)) count+=freq1[num];
        }
        for(int i=0;i<n1;i++){
            long long num=1LL*nums1[i]*nums1[i];
            if(freq2.count(num)) count+=freq2[num];
        }

        return (int)count;
    }
};