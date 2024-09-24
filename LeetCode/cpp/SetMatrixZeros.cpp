// Brute Force Solution for SetMatrixZeros.cpp:
// Time Complexity: O(n*m*(n+m))
// Space Complexity: O(1)
class Solution
{
public:
    void matrixRow(vector<vector<int>> &matrix, int n, int m, int i)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }

    void matrixCol(vector<vector<int>> &matrix, int n, int m, int j)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] != 0)
            {
                matrix[i][j] = -1;
            }
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrixRow(matrix, n, m, i);
                    matrixCol(matrix, n, m, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Better Solution for SetMatrixZeros.cpp:
// Time Complexity: O(n*m)
// Space Complexity: O(n+m)
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Optimal Solution for SetMatrixZeros.cpp:
// Time Complexity: O(n*m)
// Space Complexity: O(1)

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};