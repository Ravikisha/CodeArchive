//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int> &arr)
    {
        unordered_set<int> uset(arr.begin(), arr.end());
        int maxLen = 0;
        for (int num : arr)
        {
            if (uset.find(num - 1) == uset.end())
            {
                int len = 0;
                while (uset.find(num + len) != uset.end())
                {
                    len++;
                }
                maxLen = max(maxLen, len);
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.longestConsecutive(arr);

        cout << res << endl
             << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends