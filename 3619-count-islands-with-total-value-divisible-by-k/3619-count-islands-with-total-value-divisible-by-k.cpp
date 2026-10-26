class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]>0){
                    q.push({i, j});
                    visited[i][j]=true;
                    long long sum=0;
                    sum+=grid[i][j];
                    while(!q.empty()){
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        if(row-1>=0 && !visited[row-1][col] && grid[row-1][col]>0){
                            sum+=grid[row-1][col];
                            q.push({row-1, col});
                            visited[row-1][col]=true;
                        }
                        if(row+1<n && !visited[row+1][col] && grid[row+1][col]>0){
                            sum+=grid[row+1][col];
                            q.push({row+1, col});
                            visited[row+1][col]=true;
                        }
                        if(col-1>=0 && !visited[row][col-1] && grid[row][col-1]>0){
                            sum+=grid[row][col-1];
                            q.push({row, col-1});
                            visited[row][col-1]=true;
                        }
                        if(col+1<m && !visited[row][col+1] && grid[row][col+1]>0){
                            sum+=grid[row][col+1];
                            q.push({row, col+1});
                            visited[row][col+1]=true;
                        }
                    }
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
};