//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    // Time Complexity: O(N)
    // Space Complexity: O(1)
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        long long int xorNumber = 0;

        // XOR all numbers to find the XOR of the two unique numbers
        for (long long int num = 0; num < N; num++)
        {
            xorNumber ^= Arr[num];
        }

        // Find the rightmost set bit (without undefined behavior)
        long long int rightMost = xorNumber & -xorNumber;

        long long int num1 = 0, num2 = 0;

        // Partition the numbers based on the rightmost set bit
        for (long long int num = 0; num < N; num++)
        {
            if (Arr[num] & rightMost)
            {
                num1 ^= Arr[num]; // Group where the bit is set
            }
            else
            {
                num2 ^= Arr[num]; // Group where the bit is not set
            }
        }

        if (num1 > num2)
        {
            return {num1, num2};
        }
        else
        {
            return {num2, num1};
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int N;
        cin >> N;
        long long int Arr[N];
        for (long int i = 0; i < N; i++)
            cin >> Arr[i];
        Solution ob;
        vector<long long int> ans = ob.twoOddNum(Arr, N);
        for (long long int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends