class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            if(a[1]==b[1])return a[0]>b[0];
            return a[1]<b[1];
        });
        int a=-1,b=-1;
        int ans=0;
        for(auto &v:intervals){
            int start=v[0],end=v[1];
            bool checkA=(a>=start);
            bool checkB=(b>=start);
            if(checkA && checkB){
                continue;
            }else if(checkB){
                ans+=1;
                a=b;
                b=end;
            }else{
                ans+=2;
                a=end-1;
                b=end;
            }
            
            

        }
        return ans;
    }
};