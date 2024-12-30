//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Memoization based recursive solution
public:
    int maxMeritPoints(int day, int lastActivity, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        // Base case: If there are no days left
        if (day < 0)
        {
            return 0;
        }

        if (dp[day][lastActivity] != -1)
            return dp[day][lastActivity];

        int maxPoints = 0;

        // Iterate through all activities (0, 1, 2)
        for (int activity = 0; activity < 3; ++activity)
        {
            if (activity != lastActivity)
            { // Ensure no consecutive same activity
                int currentPoints = arr[day][activity] + maxMeritPoints(day - 1, activity, arr, dp);
                maxPoints = max(maxPoints, currentPoints);
            }
        }

        return dp[day][lastActivity] = maxPoints;
    }

    // Wrapper function
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return maxMeritPoints(n - 1, 3, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Tabulation based iterative solution
public:
    // Wrapper function
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

        for (int day = 1; day < n; day++)
        {
            for (int last = 0; last < 4; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task < 3; task++)
                {
                    if (task != last)
                    {
                        int point = arr[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends