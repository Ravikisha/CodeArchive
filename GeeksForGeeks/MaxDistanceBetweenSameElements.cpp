//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> umap;
        int dis = INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(umap.find(arr[i]) != umap.end()){
                dis = max(dis, i - umap[arr[i]]);
            }else{
                umap[arr[i]] = i;
            }
        }
        return dis;
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
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends