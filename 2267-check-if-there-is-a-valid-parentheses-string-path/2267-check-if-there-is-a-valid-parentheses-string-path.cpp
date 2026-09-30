class Solution {
public:
    bool f(vector<vector<char>>& grid, int i, int j, int open, vector<vector<vector<int>>> &dp){
        if(i==grid.size() || j==grid[0].size()) return false;
        if(grid[i][j]=='(') open++;
        else open--;
        if(open<0) return false;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if(open==0) return true;
            return false;
        }
        if(dp[i][j][open]!=-1) return dp[i][j][open];
        

        bool down = f(grid, i+1, j, open, dp);
        bool right = f(grid, i, j+1, open, dp);

        return dp[i][j][open]=down||right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
       vector<vector<vector<int>>> dp(
        grid.size(),
        vector<vector<int>>(
            grid[0].size(),
            vector<int>(grid.size()+grid[0].size(), -1)
            )
        );
        return f(grid, 0, 0, 0, dp);
    }
};