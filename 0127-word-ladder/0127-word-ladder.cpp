class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
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


                    for(int i=0;i<n;i++){
                        if(s1.size()==wordList[i].size() && !vis[i]){
                            int count=0;
                            for(int j=0;j<s1.size();j++){
                                if(s1[j]!=wordList[i][j]) count++;
                                if(count>2) break;
                            }
                            if(count==1){
                                q.push(wordList[i]);
                                vis[i]=true;
                            }
                        }
                    }
                }
            }
            return 0;
        };
        
        
        return bfs(beginWord);

    }
};