class Solution {
public:
    vector<string> ans;
    void generate(int n,string s,int i,int j){
        if(s.size()==2*n && i==n && j==n){
            ans.push_back(s);
            return ;
        }
        
        if(i<n){
            
            generate(n,s+'(',i+1,j);
        }

        if(j<i){
            generate(n,s+')',i,j+1);
        }
      
        
    }
    vector<string> generateParenthesis(int n) {
        generate(n,"",0,0);
        return ans;
    }
};