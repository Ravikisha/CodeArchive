class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int time = 0, fresh = 0, rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
            }
        }

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> cord = q.front();
                q.pop();
                for (int j = 0; j < dirs.size(); j++)
                {
                    int row = cord.first + dirs[j][0];
                    int col = cord.second + dirs[j][1];
                    // if in bounds and fresh, make rotten
                    if (row < 0 || row == rows || col < 0 || col == cols ||
                        grid[row][col] != 1)
                        continue;
                    grid[row][col] = 2;
                    q.push(make_pair(row, col));
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};