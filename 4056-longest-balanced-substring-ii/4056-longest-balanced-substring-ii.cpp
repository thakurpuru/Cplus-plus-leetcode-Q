class Solution {
public:
    int singleChar(string s){
        int l=0,n=s.size();
        int i=0;
        while(i<n){
            int j=i;
            while(j<n && s[i]==s[j]) j++;
            l=max(l,j-i);
            i=j;
        }
        return l;
    }
    int doubleChar(string s,char x, char y){
        int n=s.size();
        int i=0,l=0;
        while(i<n){
            while(i<n && (s[i]!=x && s[i]!=y)) i++;
            unordered_map<int,int>pos;
            pos[0]=i-1;
            int diff=0;
            while(i<n && (s[i]==x || s[i]==y)){
                diff+=(s[i]==x?1:-1);
                if(pos.count(diff)){
                   l=max(l,i-pos[diff]); 
                }else{
                    pos[diff]=i;
                }
                i++;
            }
        }
        return l;
    }
    int threeChar(string s,char x, char y,char z){
        int n=s.size();
        int i=0,l=0;
        while(i<n){
            while(i<n && s[i]!=x && s[i]!=y && s[i]!=z) i++;
            map<pair<int,int>,int>pos;
            pos[{0,0}]=i-1;
            int cx=0,cy=0,cz=0;
            while(i<n && (s[i]==x || s[i]==y || s[i]==z)){
                if(s[i]==x) cx++;
                else if(s[i]==y) cy++;
                else if(s[i]==z) cz++;
                pair<int,int> key = {cx - cy, cx - cz};
                if(pos.count(key)){
                   l=max(l,i-pos[key]); 
                }else{
                    pos[key]=i;
                }
                i++;
            }
        }
        return l;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int ans=0;
        ans=max(ans,singleChar(s));
        ans=max(ans,doubleChar(s,'a','b'));
        ans=max(ans,doubleChar(s,'c','b'));
        ans=max(ans,doubleChar(s,'a','c'));
        return max(ans,threeChar(s,'a','b','c'));
    }
};