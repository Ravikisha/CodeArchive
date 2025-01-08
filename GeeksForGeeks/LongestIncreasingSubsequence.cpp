//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
    // Binary Search
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(vector<int> &arr)
    {
        vector<int> temp;
        int n = arr.size();
        temp.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
            }
            else
            {
                int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[idx] = arr[i];
            }
        }
        return temp.size();
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--)
    {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.longestSubsequence(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends