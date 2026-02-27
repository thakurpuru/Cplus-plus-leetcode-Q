class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int j=1;
        vector<int> ans;
        vector<bool> check(n+1,false);
        check[1]=true;
        ans.push_back(j);
        for(int i=1;i<n;i++){
            if(k!=1){
                if(j-k>0 && !check[j-k]){
                    j-=k;
                }else if(j+k<=n && !check[j+k]){
                    j+=k;
                }
                k--;
            }else{
                break;
            }
            check[j]=true;
            ans.push_back(j);
        }
        for(int i=1;i<=n;i++){
            if(!check[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};