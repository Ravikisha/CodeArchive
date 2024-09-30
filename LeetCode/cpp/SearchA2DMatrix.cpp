class Solution
{
    // Time Complexity:  O(n log n + m log n)
    // Space Complexity: O(1)
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, bottom = n - 1;
        // Find the row where the target element is present.
        while (top <= bottom)
        {
            int row = top + (bottom - top) / 2;
            if (target > matrix[row][m - 1])
                top = row + 1;
            else if (target < matrix[row][0])
                bottom = row - 1;
            else
                break;
        }
        // If the target element is not present in the matrix, return false.
        if (!(top <= bottom))
            return false;
        int row = top + (bottom - top) / 2;
        int left = 0, right = m - 1;
        // Find the column where the target element is present.
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target > matrix[row][mid])
                left = mid + 1;
            else if (target < matrix[row][mid])
                right = mid - 1;
            else
                return true;
        }
        return false;
    }
};