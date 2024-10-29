class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int j = n - i - 1;
            sum += mat[i][i];
            sum += mat[i][j];
        }
        if (n % 2 != 0)
        {
            sum -= mat[n / 2][n / 2];
        }
        return sum;
    }
};