class Solution {
public:
    string ans;
    void solve(unordered_set<string> &st,string &s,int start,int n,string s1){
        if(s1.size()==n){
            if(!st.count(s1)){
                ans=s1;
            }
            return ;
        }
        for(int i=start;i<s.size();i++){
            solve(st,s,i,n,s1+s[i]);
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {
        string s="01";
        ans="";
        int n=nums.size();
        unordered_set<string> st(nums.begin(),nums.end());
        solve(st,s,0,n,"");
        return ans;
    }
};