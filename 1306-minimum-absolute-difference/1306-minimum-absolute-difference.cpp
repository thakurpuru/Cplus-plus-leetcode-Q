class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int sz=arr.size();
        
        int n=abs(arr[0]-arr[1]);
        for(int i=0;i<sz-1;i++){
            if(abs(arr[i+1]-arr[i])<n) n=abs(arr[i+1]-arr[i]);
        }
        int i=0,j=1;
        
        while(j<arr.size()){
            if(n==abs(arr[i]-arr[j])){
                ans.push_back({arr[i],arr[j]});
            }
            i++;j++;
        }
        return ans;

    }
};