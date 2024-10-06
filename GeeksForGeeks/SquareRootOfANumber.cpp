//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution
{
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
public:
    long long int floorSqrt(long long int n)
    {
        long long int low = 0;
        long long int high = n;
        long long int result = 0;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if (mid * mid <= n)
            {
                result = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
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
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends