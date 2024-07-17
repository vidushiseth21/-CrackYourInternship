class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int fresh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1)
                {
                    fresh++;
                }
                else
                {
                    visited[i][j]=0;
                }
            }
        }
        int c=0;
        int time=0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int w=q.front().second;
            time=max(w,time);
            q.pop();
            for(auto d:directions)
            {
                int new_row=i+d.first;
                int new_col=j+d.second;
                if(new_row<n && new_row>=0 && new_col<m && new_col>=0 && !visited[new_row][new_col] && grid[new_row][new_col]==1)
                {
                    visited[new_row][new_col]=1;
                    q.push({{new_row,new_col},w+1});
                    c++;
                }
            }
        }
        if(c!=fresh)
         return -1;
        return time;
    }
};