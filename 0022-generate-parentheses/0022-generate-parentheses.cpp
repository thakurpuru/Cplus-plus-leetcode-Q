class Solution {
public:
    vector<string> ans;
    void generate(int n,string& s,int i,int j){
        if(s.length()==2*n && i==n && j==n){
            ans.push_back(s);
            return ;
        }
        
        if(i<n){
            s+='(';
            generate(n,s,i+1,j);
            s.pop_back();
        }

        if(j<i){
            s+=')';
            generate(n,s,i,j+1);
            s.pop_back();
        }
      
        
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(n,s,0,0);
        return ans;
    }
};