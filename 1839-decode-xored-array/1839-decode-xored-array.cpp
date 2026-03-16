class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int n=first;
        for(int i=0;i<encoded.size();i++){
            int temp=encoded[i]^n;
            ans.push_back(temp);
            n=temp;
        }
        return ans;
    }
};