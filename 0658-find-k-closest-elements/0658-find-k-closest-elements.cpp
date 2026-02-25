class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        int i=0,j=n-k;
        while(i<j){
            int mid=(i+j)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                i=mid+1;
            }else{
                j=mid;
            }
        }
        
        return vector<int> (arr.begin()+i,arr.begin()+i+k);
        
    }
};