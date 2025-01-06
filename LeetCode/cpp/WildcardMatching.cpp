class Solution
{
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (p[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

class Solution
{
    // Time Complexity: O(n*m)
    // Space Complexity: O(m)
    // Bottom-up Dynamic Programming (Tabulation) with Space Optimization
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();
        vector<bool> dp(m + 1, false), curr(m + 1, false);

        dp[0] = true;
        for (int j = 1; j <= m; j++)
        {
            dp[j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            int flag = true;
            for (int ii = 1; ii <= i; ii++)
            {
                if (p[ii - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++)
            {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                {
                    curr[j] = dp[j - 1];
                }
                else if (p[i - 1] == '*')
                {
                    curr[j] = dp[j] | curr[j - 1];
                }
                else
                    curr[j] = false;
            }
            dp = curr;
        }
        return dp[m];
    }
};