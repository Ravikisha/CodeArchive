//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n*target)
    // Space Complexity: O(target)
public:
    int countPartitions(vector<int> &arr, int d)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        const int MOD = 1e9 + 7; // To avoid overflow, use modulo operation.
        int n = arr.size();
        if (sum - d < 0 || (sum - d) % 2)
            return 0;
        int target = (sum - d) / 2;
        vector<int> dp(target + 1, 0);
        if (arr[0] == 0)
            dp[0] = 2;
        else
            dp[0] = 1;

        // Initialize the first element.
        if (arr[0] != 0 && arr[0] <= target)
            dp[arr[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int tar = target; tar >= 0; tar--)
            {
                if (arr[i] <= tar)
                {
                    dp[tar] = (dp[tar] + dp[tar - arr[i]]) % MOD;
                }
            }
        }

        return dp[target];
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--)
    {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number)
        {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends