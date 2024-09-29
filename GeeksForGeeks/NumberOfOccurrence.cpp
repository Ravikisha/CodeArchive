//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    // Time complexity: O(log(n))
    // Space complexity: O(1)
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    
        // Helper lambda function to find the first occurrence of target
        auto findFirst = [&](int target) -> int {
            int left = 0, right = n - 1, index = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    index = mid;  // Save the index, but continue searching left
                    right = mid - 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return index;
        };

        // Helper lambda function to find the last occurrence of target
        auto findLast = [&](int target) -> int {
            int left = 0, right = n - 1, index = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == target) {
                    index = mid;  // Save the index, but continue searching right
                    left = mid + 1;
                } else if (arr[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return index;
        };

        // Find the first and last occurrence of the target
        int first = findFirst(x);
        if(first == -1) return 0;
        int last = findLast(x);
        return last-first+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends