//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        if(arr.size() < 3){
            return -1;
        }
        
        int first, second, third;
        first = second = third = INT_MIN;
        
        // if the current element is greater than first
        for(int i=0;i<arr.size();i++){
            if(arr[i] > first){
                third = second;
                second = first;
                first = arr[i];
            }
            // if the arr[i] is in between first and second then update second
            else if(arr[i] > second && arr[i] <= first){
                third = second;
                second = arr[i];
            }
            // if the arr[i] is in before the second element
            else if(arr[i] > third && arr[i] <= second && arr[i] <= first){
                third = arr[i];
            }
            
        }
        return third;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.thirdLargest(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends