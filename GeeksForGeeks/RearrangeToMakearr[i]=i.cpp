//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> modifyArray(vector<int>& arr) {
        int len = arr.size();

        // Iterate through the array
        for (int i = 0; i < len; i++) {
            // Continue swapping until we place the element in its correct position
            while (arr[i] != -1 && arr[i] != i && arr[i] < len) {
                // Swap arr[i] with arr[arr[i]] only if arr[i] is within valid range
                if (arr[arr[i]] == arr[i]) break; // Avoid infinite loop for duplicate elements
                swap(arr[i], arr[arr[i]]);
            }
        }
    
        // Set any remaining incorrect positions to -1
        for (int i = 0; i < len; i++) {
            if (arr[i] != i) {
                arr[i] = -1;
            }
        }
    
        return arr;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        // cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends