class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        while(n>0){
            vec.push_back(n%10);
            n/=10;
        }
        int m=vec.size();
        if(m==1) return n;
        sort(vec.begin(),vec.end());
        return vec[m-1]*vec[m-2];
    }
};