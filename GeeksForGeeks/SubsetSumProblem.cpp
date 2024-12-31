//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time complexity: O(n*target)
    // Space complexity: O(n*target)
    // Top-down approach (Memoization)
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        function<bool(int, int)> recursive = [&](int i, int tar)
        {
            if (tar == 0)
                return true;
            if (i == 0)
                return (arr[0] == tar);
            if (dp[i][tar] != -1)
                return (bool)dp[i][tar];
            bool notTake = recursive(i - 1, tar);
            bool take = false;
            if (tar >= arr[i])
            {
                take = recursive(i - 1, tar - arr[i]);
            }
            dp[i][tar] = (notTake || take);
            return (notTake || take);
        };
        return recursive(arr.size() - 1, target);
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time complexity: O(n*target)
    // Space complexity: O(n*target)
    // Bottom-up approach (Tabulation)
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                bool notTake = dp[i - 1][tar];
                bool take = false;
                if (arr[i] <= tar)
                    take = dp[i - 1][tar - arr[i]];
                dp[i][tar] = notTake | take;
            }
        }
        return dp[n - 1][target];
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
    // Time complexity: O(n*target)
    // Space complexity: O(target)
    // Bottom-up approach (Tabulation) with space optimization
public:
    bool isSubsetSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<bool> dp(target + 1, false);
        vector<bool> curr(target + 1, false);
        dp[0] = curr[0] = true;
        dp[arr[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                bool notTake = dp[tar];
                bool take = false;
                if (arr[i] <= tar)
                    take = dp[tar - arr[i]];
                curr[tar] = notTake | take;
            }
            dp = curr;
        }
        return dp[target];
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends