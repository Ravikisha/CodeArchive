//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // Time Complexity: O(N)
    // Space Complexity: O(K)
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for(vector<int> cord: points){
            int distance = sqrt(pow(cord[0] - 0, 2) + pow(cord[1] - 0, 2));
            maxHeap.push(make_pair(distance, make_pair(cord[0], cord[1])));
            
            if(maxHeap.size() > k) maxHeap.pop();
        }
        
        vector<vector<int>> result;
        while(!maxHeap.empty()){
            pair<int, pair<int, int>> top = maxHeap.top();
            result.push_back({top.second.first, top.second.second});
            maxHeap.pop();
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends