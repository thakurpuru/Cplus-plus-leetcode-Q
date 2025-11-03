class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        int n=colors.size();
        int sum=0;
        int curr_max=0;
       
        for(int i=0;i<colors.size();i++){
            
            if(i+1<n && colors[i]==colors[i+1]){
                if(neededTime[i]>curr_max) curr_max=neededTime[i];
                sum+=neededTime[i];
            }else if(i-1>=0 && colors[i]==colors[i-1]){
                if(neededTime[i]>curr_max) curr_max=neededTime[i];
                sum+=neededTime[i];
                ans=ans+(sum-curr_max);
                curr_max=0;
                sum=0;
                
            }
        }
        return ans;
    }
};