//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    void bitManipulation(int num, int i)
    {
        int temp = num;
        // Get the ith bit (1-based index)
        int ithBit = (temp & (1 << (i - 1))) >> (i - 1);
        cout << ithBit << " ";

        // Set the ith bit
        temp = temp | (1 << (i - 1));
        cout << temp << " ";

        // Clear the ith bit
        temp = (temp & ~(1 << (i - 1)));
        cout << temp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends