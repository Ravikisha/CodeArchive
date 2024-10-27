//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool findTriplet(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            int target = arr[i];
            int left = 0, right = n - 1;

            // Use two-pointer approach to find if there's a pair summing to `target`
            while (left < right)
            {
                if (left == i)
                    left++; // Skip the current target element
                else if (right == i)
                    right--; // Skip the current target element
                else
                {
                    int sum = arr[left] + arr[right];
                    if (sum == target)
                    {
                        return true;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends