// Time Limit Exceeded
class Solution
{
    // Time Complexity: O(N * 4^L) where N is the number of cells in the board and L is the length of the word
    // Space Complexity: O(L) where L is the length of the word
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        int n = word.size();
        std::set<std::pair<int, int>> path; // Use set instead of unordered_set for pairs

        // Recursive backtracking function to search for the word
        std::function<bool(int, int, int)> backtrack = [&](int r, int c, int i)
        {
            // Base case: if all characters are found, return true
            if (i == n)
                return true;

            // Boundary and condition checks
            if (r < 0 || c < 0 || r >= rows || c >= cols ||
                word[i] != board[r][c] ||
                path.find(std::make_pair(r, c)) != path.end())
                return false;

            // Mark the current cell as visited by adding to path
            path.emplace(std::make_pair(r, c));

            // Explore all four directions
            bool result =
                (backtrack(r + 1, c, i + 1) ||
                 backtrack(r - 1, c, i + 1) ||
                 backtrack(r, c + 1, i + 1) ||
                 backtrack(r, c - 1, i + 1));

            // Backtrack: remove the cell from path set
            path.erase(std::make_pair(r, c));

            return result;
        };

        // Iterate over each cell in the board to start the search
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Start the search from the current cell
                if (backtrack(i, j, 0))
                    return true;
            }
        }

        // If no path found for the word, return false
        return false;
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(N * 4^L) where N is the number of cells in the board and L is the length of the word
    // Space Complexity: O(L) where L is the length of the word
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        int n = word.size();

        // Define the recursive backtracking function
        std::function<bool(int, int, int)> backtrack = [&](int r, int c, int i)
        {
            // Base case: All characters are matched
            if (i == n)
                return true;

            // Boundary checks and character matching
            if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != word[i])
                return false;

            // Mark the cell as visited by replacing with a temporary character
            char temp = board[r][c];
            board[r][c] = '#'; // Use '#' as a placeholder for visited

            // Explore all four directions: down, up, right, left
            bool result = (backtrack(r + 1, c, i + 1) ||
                           backtrack(r - 1, c, i + 1) ||
                           backtrack(r, c + 1, i + 1) ||
                           backtrack(r, c - 1, i + 1));

            // Restore the cell's original value during backtracking
            board[r][c] = temp;

            return result;
        };

        // Try starting from each cell
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // Start DFS from the current cell if it matches the first character
                if (board[i][j] == word[0] && backtrack(i, j, 0))
                    return true;
            }
        }

        // If no path was found, return false
        return false;
    }
};