class Solution {
public:
    unordered_map<int,vector<int>> mp;
    bool iscycle(int src,vector<bool>&vis,vector<bool>&recpath){
        vis[src]=true;
        recpath[src]=true;
        for(auto v:mp[src]){
            if(!vis[v]){
                
                if(iscycle(v,vis,recpath)) return true;
            }else if(recpath[v]) return true;
        }
        recpath[src]=false;
        return false;
    }
    void topological(int src,vector<bool>&vist,stack<int>&st){
        vist[src]=true;
        for(auto v:mp[src]){
            if(!vist[v]){
                topological(v,vist,st);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vec;
        if(prerequisites.size()==0){
            for(int i=numCourses-1;i>=0;i--)
            vec.push_back(i);
            return vec;
        }
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            mp[v].push_back(u);
        }
        vector<bool> vis(numCourses,false), rec(numCourses,false);
        int check=0;
        for(auto i:mp){
            if(!vis[i.first]){
                if(iscycle(i.first,vis,rec)) return {};
            }
        }
        if(check==1){
            for(int i=numCourses-1;i>=0;i--){
                if(!mp.count(i)){
                    vec.push_back(i);
                }
            }
            return vec;
        }

        stack<int> st;
        vector<bool> vist(numCourses,false);

        for(auto i:mp){
            if(!vist[i.first]){
                topological(i.first,vist,st);
            }
        }
        while(!st.empty()){
            vec.push_back(st.top());
            st.pop();
        }
       for(int i=numCourses-1;i>=0;i--){
            if(!vist[i]){
                vec.push_back(i);
            }
       }
        return vec;

    }
};