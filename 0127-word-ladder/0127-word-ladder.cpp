class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord)){
            return 0;
        }
        int n=wordList.size();
        vector<bool> vis(n);
        queue<string> q;
        int ans=0;
        function<int(string)>bfs=[&](string s){
            q.push(s);
            while(q.size()>0){
                int size=q.size();
                ans++;
                for(int k=0;k<size;k++){
                    string s1=q.front();
                    q.pop();
                    if(s1==endWord) return ans;


                    for(int i=0;i<s1.size();i++){
                        char org=s1[i];
                            for(int j=0;j<26;j++){
                                s1[i]='a'+j;
                                if(st.count(s1)){
                                    q.push(s1);
                                    st.erase(s1);
                                }
                            }
                            s1[i]=org;
                        
                    }
                }
            }
            return 0;
        };
        
        
        return bfs(beginWord);

    }
};