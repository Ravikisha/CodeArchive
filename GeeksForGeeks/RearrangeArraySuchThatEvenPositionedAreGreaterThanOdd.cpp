//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Checking if the answer is correct or not
bool checkOrder(vector<int>& ans, int n) {
    if (ans.size() != n) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        if (i % 2 != 0) { // Odd index
            if (ans[i] < ans[i - 1]) {
                return false;
            }
        } else { // Even index
            if (ans[i] > ans[i - 1]) {
                return false;
            }
        }
    }
    return true;
}


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        for(int i=1;i<n;i++){
            // check if the index is even (1-based) => i+1 is even
            if((i+1)%2 == 0){
                // Ensure arr[i] >= arr[i-1] else swap the values
                if(arr[i] < arr[i-1]){
                    swap(arr[i], arr[i-1]);
                }
            }else{
                // Ensure arr[i] <= arr[i11] else swap the values
                if(arr[i] > arr[i-1]){
                    swap(arr[i], arr[i-1]);
                }
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
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }

        Solution ob;
        vector<int> ans = ob.rearrangeArray(nums);
        bool check_ans = checkOrder(ans, nums.size());
        if (check_ans) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
    return 0;
}

// } Driver Code Ends