class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : directions)
            {
                int new_row=dir.first+row;
                int new_col=dir.second+col;
                if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && grid[new_row][new_col]=='1' && !visited[new_row][new_col])
                {
                    q.push({new_row,new_col});
                    visited[new_row][new_col]=1;
                }
            }
            
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1'){
                count++;
                bfs(grid,visited,i,j);}
            }
        }
        return count;
    }
};