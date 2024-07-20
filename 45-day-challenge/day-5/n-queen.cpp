class Solution {
private:
    unordered_set<int> cols;         // Set to track occupied columns
    unordered_set<int> negDiagonal;  // Set to track occupied negative diagonals (row - col)
    unordered_set<int> posDiagonal;  // Set to track occupied positive diagonals (row + col)
    
    void solve(int n, int row, vector<vector<string>>& res, vector<string>& board){
        // Base case: If all queens are placed (reached last row), append the current board configuration to the result
        if(row == n){
            res.push_back(board);
            return; 
        }
        
        // Iterate through each column
        for(int col = 0; col < n; col++){
            // Check if placing a queen at position (row, col) violates any constraints
            if(cols.count(col) || negDiagonal.count(row - col) || posDiagonal.count(row + col))
                continue;
            
            // Update occupied columns and diagonals
            cols.insert(col);
            negDiagonal.insert(row - col);
            posDiagonal.insert(row + col);
            board[row][col] = 'Q';  // Place the queen
            
            // Recursive call to place queens in the next row
            solve(n, row + 1, res, board);
            
            // Backtrack: Remove the queen and reset states of occupied columns and diagonals
            cols.erase(col);
            negDiagonal.erase(row - col);
            posDiagonal.erase(row + col);
            board[row][col] = '.';
        }
    }
   
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));  // Initialize the board with empty cells
        solve(n, 0, ans, board);  // Start backtracking from the first row
        return ans;
    }
};