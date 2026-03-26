class Solution {
public:
    char kthCharacter(int k) {
        int n=k;
        string word="a";
        while(n>0){
            string temp="";

            for(int i=0;i<word.size();i++){
                temp+=(word[i]+1);
            }
            word+=temp;
            n>>=1;
            if(word.size()>k){
                break;
            }
        }
        return word[k-1];
    }
};