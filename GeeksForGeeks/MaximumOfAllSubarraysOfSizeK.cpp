//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> result;
        deque<int> Q(k);
        int i;
        for(i=0; i< k; i++){
            while((!Q.empty()) && arr[i] >= arr[Q.back()])
                Q.pop_back();
            if(Q.size() == 0 || arr[Q.back()] > arr[i]){
                Q.push_back(i);
            }
        }
        result.push_back(arr[Q.front()]);
        for(i = k; i< n;i++){
            if(Q.front() == i-k)
                Q.pop_front();
            while(Q.size() > 0 && arr[Q.back()] <= arr[i])
                Q.pop_back();
            if(Q.size() == 0 || arr[Q.back()] > arr[i])
                Q.push_back(i);
            
            result.push_back(arr[Q.front()]);
        }
        return result;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends