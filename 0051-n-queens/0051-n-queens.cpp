class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        
        auto backtrack = [&](auto&& self, int row) -> void {
            if (row == n) {
                result.push_back(board);
                return;
            }
            
            for (int c = 0; c < n; ++c) {
                int d1 = row + c;
                int d2 = row - c + n - 1;
                if (col[c] || diag1[d1] || diag2[d2]) {
                    continue;
                }
                
                // Place queen
                board[row][c] = 'Q';
                col[c] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                
                self(self, row + 1);
                
                // Backtrack
                board[row][c] = '.';
                col[c] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        };
        
        backtrack(backtrack, 0);
        return result;
    }
};
