class Solution {
public:
    int dfs(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& memo){
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return 0;
        
        // If already computed, return the cached result
        if (memo[i][j] != 0) return memo[i][j];
        
        int maxPath = 1; // At least the current cell itself
        
        // Check all four directions
        if (i > 0 && matrix[i-1][j] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + dfs(matrix, i-1, j, memo));
        }
        if (j > 0 && matrix[i][j-1] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + dfs(matrix, i, j-1, memo));
        }
        if (i < matrix.size()-1 && matrix[i+1][j] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + dfs(matrix, i+1, j, memo));
        }
        if (j < matrix[0].size()-1 && matrix[i][j+1] > matrix[i][j]) {
            maxPath = max(maxPath, 1 + dfs(matrix, i, j+1, memo));
        }
        
        // Store in memoization table
        memo[i][j] = maxPath;
        return maxPath;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<int> path;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxLength=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                maxLength = max(maxLength, dfs(matrix, i, j, memo));
                
            }
        }
        return maxLength;
    }
};