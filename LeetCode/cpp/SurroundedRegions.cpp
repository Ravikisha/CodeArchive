class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
public:
    void solve(vector<vector<char>> &board)
    {
        int rows = board.size(), cols = board[0].size();
        // Helper function to mark connected 'O's
        function<void(int, int)> capture = [&](int r, int c)
        {
            if (r < 0 || r == rows || c < 0 || c == cols || board[r][c] != 'O')
                return;
            board[r][c] = 'T';
            capture(r + 1, c);
            capture(r - 1, c);
            capture(r, c + 1);
            capture(r, c - 1);
        };
        // Capture all border 'O's and connected 'O's
        for (int r = 0; r < rows; r++)
        {
            capture(r, 0);
            capture(r, cols - 1);
        }
        for (int c = 0; c < cols; c++)
        {
            capture(0, c);
            capture(rows - 1, c);
        }
        // Convert remaining 'O's to 'X's and 'T's back to 'O's
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == 'T')
                {
                    board[r][c] = 'O';
                }
            }
        }
    }
};