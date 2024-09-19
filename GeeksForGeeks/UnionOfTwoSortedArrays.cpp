//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;
        int index1=0, index2=0;
        while(index1 < n && index2 < m){
            if(arr1[index1] == arr2[index2]){
                if(result.empty() || result[result.size()-1] != arr1[index1])
                    result.push_back(arr1[index1]);
                index1++;
                index2++;
            }
            else if(arr1[index1] > arr2[index2]){
                if(result.empty() || result[result.size()-1] != arr2[index2])
                    result.push_back(arr2[index2]);
                index2++;
            }else if(arr1[index1] < arr2[index2]){
                if(result.empty() || result[result.size()-1] != arr1[index1])
                    result.push_back(arr1[index1]);
                index1++;
            }
        }
        while(index1 < n){
            if(result.empty() || result[result.size()-1] != arr1[index1])
                result.push_back(arr1[index1]);
            index1++;
        }
        while(index2 < m){
            if(result.empty() || result[result.size()-1] != arr2[index2])
                result.push_back(arr2[index2]);
            index2++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends