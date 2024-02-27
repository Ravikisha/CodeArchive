//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if((S > 9*N) || (N != 1 && S==0)) return "-1";
        int a = S/9;
        int b = S%9;
        string result;
        for(int i=0;i<a;i++){
            result += "9";
        }
        if(a <N){
            result += to_string(b);
            for(int i=0;i<N-a-1;i++){
                result += "0";
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends