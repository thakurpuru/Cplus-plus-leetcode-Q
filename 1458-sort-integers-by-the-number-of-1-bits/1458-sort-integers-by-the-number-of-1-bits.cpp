class Solution {
public:
    static bool solve(int a,int b){
        int i=__builtin_popcount(a);
        int j=__builtin_popcount(b);
        if(i==j) return a<b;
        return i<j;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),solve);
        return arr;
    }
};