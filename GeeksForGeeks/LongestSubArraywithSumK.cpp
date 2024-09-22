//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int maxLen = 0;
        map<int, int> sumMap;
        int sum = 0;
        for(int i=0;i<N;i++){
            sum += A[i];
            if(sum == K){
                maxLen = max(maxLen, i+1);
            }
            int rem = sum -K;
            if(sumMap.find(rem) != sumMap.end()){
                int len = i-sumMap[rem];
                maxLen = max(maxLen, len);
            }
            if(sumMap.find(sum) == sumMap.end()){
                sumMap[sum] = i;
            }
        }
        return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends