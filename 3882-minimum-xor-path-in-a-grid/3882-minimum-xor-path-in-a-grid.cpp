class Solution {
public:
    int f(vector<vector<int>> &grid, int i, int j, int ans, int n, int m, vector<vector<vector<int>>> &dp){
        if(i==n-1 && j==m-1) return ans^grid[i][j];
        if(i==n || j==m) return INT_MAX;
        ans^=grid[i][j];
        
        if(dp[i][j][ans]!=-1) return dp[i][j][ans];
        int temp1 = INT_MAX;
        int temp2 = INT_MAX;
        
        if(i+1<n){
            temp1 = f(grid, i+1, j, ans, n, m, dp);
        }
        if(j+1<m){
            temp2 = f(grid, i, j+1, ans, n, m, dp);
        }
        return dp[i][j][ans] = min(temp1, temp2);

    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(1024,-1)));
        return f(grid, 0, 0, 0, n, m, dp);
    }
};