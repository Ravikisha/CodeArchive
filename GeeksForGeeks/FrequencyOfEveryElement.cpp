//{ Driver Code Starts
//Initial Template for C++

#include "bits/stdc++.h"
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    vector<int> frequency(int n, vector<int> &a){
        vector<int> result;
        unordered_map<int, int> umap;
        for(auto it: a){
            if (umap[it]){
                umap[it]++;
            }else{
                umap[it] = 1;
            }
        }
        for(int i=0;i<n;i++){
            result.push_back(umap[a[i]]);
            umap[a[i]]--;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        vector<int>ans=ob.frequency(n, a);
        for(auto it:ans)
            cout<<it<<" ";
        cout<<endl;
    }
}
// } Driver Code Ends