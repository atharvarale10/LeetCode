#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        int count = 0;
        
        auto backtrack = [&](auto&& self, int row) -> void {
            if (row == n) {
                ++count;
                return;
            }
            
            for (int c = 0; c < n; ++c) {
                int d1 = row + c;
                int d2 = row - c + n - 1;
                if (col[c] || diag1[d1] || diag2[d2]) {
                    continue;
                }
                
                col[c] = true;
                diag1[d1] = true;
                diag2[d2] = true;
                
                self(self, row + 1);
                
                col[c] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        };
        
        backtrack(backtrack, 0);
        return count;
    }
};