//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    // k is the maximum number of zeros allowed to flip
    int maxOnes(vector<int> &nums, int k)
    {
        int l = 0, maxLen = 0;
        int n = nums.size();
        int ones = 0;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 1)
                ones++;
            while ((r - l + 1) - ones > k)
            {
                if (nums[l] == 1)
                    ones--;
                l++;
            }
            if ((r - l + 1) - ones <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
        }
        return maxLen;
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends