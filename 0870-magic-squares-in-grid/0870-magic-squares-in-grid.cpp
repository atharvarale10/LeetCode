class Solution {
private:
 
    bool isMagic(vector<vector<int>>& g, int i, int j) {
    
        if (g[i][j] != 5) return false;

        bool seen[10] = {false};
        for (int r = i - 1; r <= i + 1; ++r) {
            for (int c = j - 1; c <= j + 1; ++c) {
                int val = g[r][c];
                if (val < 1 || val > 9 || seen[val]) return false;
                seen[val] = true;
            }
        }

        if (g[i-1][j-1] + g[i-1][j] + g[i-1][j+1] != 15) return false;
        if (g[i  ][j-1] + g[i  ][j] + g[i  ][j+1] != 15) return false;
        if (g[i+1][j-1] + g[i+1][j] + g[i+1][j+1] != 15) return false;

        if (g[i-1][j-1] + g[i][j-1] + g[i+1][j-1] != 15) return false;
        if (g[i-1][j  ] + g[i][j  ] + g[i+1][j  ] != 15) return false;
        if (g[i-1][j+1] + g[i][j+1] + g[i+1][j+1] != 15) return false;

        if (g[i-1][j-1] + g[i][j] + g[i+1][j+1] != 15) return false;
        if (g[i-1][j+1] + g[i][j] + g[i+1][j-1] != 15) return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m < 3 || n < 3) return 0;

        int count = 0;
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (isMagic(grid, i, j)) count++;
            }
        }
        return count;
    }
};
