class Solution {
public:
    int minPartitions(string n) {
        int max_d=0;
        for(char c:n){
            max_d=max(max_d,c-'0');
        }   
        return max_d;
    }
};