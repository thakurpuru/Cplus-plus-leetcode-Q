class Solution {
public:
    void dfs(vector<vector<int>>& grid, set<int>& heap, int i, int j){

        int m = grid.size(), n = grid[0].size();

        int sum = grid[i][j-1] + grid[i][j+1] + grid[i-1][j] + grid[i+1][j];
        heap.insert(sum);
        if(heap.size() > 3) heap.erase(heap.begin());

        for(int k = 2; k < min(m,n); k++){
            if(i-k>=0 && i+k<m && j-k>=0 && j+k<n){

                int dx=1,dy=1;
                int x=i-k,y=j;
                int sm=0;

                do{
                    sm += grid[x][y];
                    x += dx;
                    y += dy;

                    if(x==i && y==j+k){
                        dx=1; dy=-1;
                    }
                    else if(x==i+k && y==j){
                        dx=-1; dy=-1;
                    }
                    else if(x==i && y==j-k){
                        dx=-1; dy=1;
                    }

                }while(!(x==i-k && y==j));

                heap.insert(sm);
                if(heap.size()>3) heap.erase(heap.begin());
            }
            else break;
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        set<int> pq;

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                dfs(grid,pq,i,j);
            }
        }

        for(int i=0;i<m;i++){
            pq.insert(grid[i][0]);
            pq.insert(grid[i][n-1]);
            while(pq.size()>3) pq.erase(pq.begin());
        }

        for(int j=1;j<n-1;j++){
            pq.insert(grid[0][j]);
            pq.insert(grid[m-1][j]);
            while(pq.size()>3) pq.erase(pq.begin());
        }

        vector<int> ans;

        for(auto x:pq)
            ans.push_back(x);

        sort(ans.begin(),ans.end(),greater<int>());

        return ans;
    }
};