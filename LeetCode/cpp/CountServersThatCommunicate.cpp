class Solution {
    // Time Complexity: O(n*m)
    // Space Complexity: O(n+m)
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row = vector<int>(m, 0);
        vector<int> column = vector<int>(n, 0);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)
                    continue;
                row[r]++;
                column[c]++;
            }
        }

        int ans = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0)
                    continue;
                if (row[r] == 1 && column[c] == 1)
                    continue;
                ans++;
            }
        }

        return ans;
    }
};