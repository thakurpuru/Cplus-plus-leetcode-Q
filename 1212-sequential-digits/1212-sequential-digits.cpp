class Solution {
public:
    // void solve(long long num,int low,int high,int i){
    //     if(num>high){
    //         return;
    //     }
    //     if(num>low && num<high){
    //         ans.push_back(num);
    //         return;
    //     }
    //     for(int j=i;j<=9;j++){
    //         long long res=(num*10)+j;
    //         solve(res,low,high,j+1);
    //     }

    // }
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for(int i=1;i<=9;i++){
            int num=i;
            int dig=i+1;
            while(num<=high && dig<=9){
                num=(num*10)+dig;
                if(num>=low && num<=high) ans.push_back(num);
                dig++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};