//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int totalElements(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> umap;
        int total = 0, l = 0;
        for (int r = 0; r < n; r++)
        {
            umap[arr[r]]++;
            while (umap.size() > 2)
            {
                umap[arr[l]]--;
                if (umap[arr[l]] == 0)
                    umap.erase(arr[l]);
                l++;
            }
            total = max(total, r - l + 1);
        }
        return total;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--)
    {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends