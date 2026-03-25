class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        long long totalsum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                totalsum+=grid[i][j];
            }
        }
        long long sum=0;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
            }
            if(sum==totalsum-sum) return true;
            else if(sum>totalsum-sum) break;
        }
        sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sum+=grid[j][i];
            }
            if(sum==totalsum-sum) return true;
            else if(sum>totalsum-sum) break;
        }
        return false;

    }
};