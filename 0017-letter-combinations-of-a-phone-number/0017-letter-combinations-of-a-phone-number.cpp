class Solution {
public:
    vector<string> ans;
    void solve(string digit,string out,int i,string map[]){
        if(i>=digit.size()){
            ans.push_back(out);
            return;
        }
        int val=digit[i]-'0';
        string s1=map[val];
        for(int j=0;j<s1.size();j++){
            solve(digit,out+s1[j],i+1,map);   
        }


    }
    vector<string> letterCombinations(string digits) {
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        solve(digits,"",0,map);
        return ans;
    }
};