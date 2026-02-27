class Solution {
public:
    int mod=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int nh=horizontalCuts.size();
        int nv=verticalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int height=horizontalCuts[0],width=verticalCuts[0];
        for(int i=0;i<nh-1;i++){
            height=max(height,horizontalCuts[i+1]-horizontalCuts[i]);
        }
        height=max(height,h-horizontalCuts[nh-1]);
        for(int i=0;i<nv-1;i++){
            width=max(verticalCuts[i+1]-verticalCuts[i],width);
        }
        width=max(w-verticalCuts[nv-1],width);
        height%=mod;
        width%=mod;
        long long ans=1LL*height*width;
        return ans%mod;
    }
};