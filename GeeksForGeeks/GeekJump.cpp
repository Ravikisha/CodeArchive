//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Top Down Approach
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        function<int(int)> backtracking = [&](int i)
        {
            if (i == 0)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            int left = backtracking(i - 1) + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = backtracking(i - 2) + abs(height[i] - height[i - 2]);
            }
            return dp[i] = min(left, right);
        };
        return backtracking(n - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";

        cout << "~" << "\n";
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
    // Bottom Up Approach
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int left = dp[i - 1] + abs(height[i] - height[i - 1]);
            int right = INT_MAX;
            if (i > 1)
            {
                right = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(left, right);
        }
        return dp[n - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";

        cout << "~" << "\n";
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
    // Space Complexity: O(1)
    // Bottom Up Approach
public:
    int minimumEnergy(vector<int> &height, int n)
    {
        int prev1 = 0;  // Minimum energy to reach the previous stair
        int prev2 = 0;  // Minimum energy to reach two stairs before
        int result = 0; // To store the minimum energy for the current stair

        for (int i = 1; i < n; i++)
        {
            int left = prev1 + abs(height[i] - height[i - 1]); // Jump from i-1 to i
            int right = INT_MAX;

            if (i > 1)
            {
                right = prev2 + abs(height[i] - height[i - 2]); // Jump from i-2 to i
            }

            result = min(left, right); // Minimum energy to reach the i-th stair
            prev2 = prev1;             // Update prev2 for the next iteration
            prev1 = result;            // Update prev1 for the next iteration
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends