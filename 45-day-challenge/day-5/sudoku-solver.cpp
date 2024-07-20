class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int n,int row,int col,char c)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][col]==c)
             return false;
            if(board[row][i]==c)
             return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
             return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n=board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char val='1';val<='9';val++)
                    {
                        if(isSafe(board,n,i,j,val))
                        {
                            board[i][j]=val;
                            if(solve(board))
                                return true;
                            else
                             board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};