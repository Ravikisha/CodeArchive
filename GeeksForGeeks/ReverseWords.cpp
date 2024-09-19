//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        stack<string> st;
        string result = "";
        for(int i=0;i<str.size();i++){
            if(str[i] != '.'){
               result += str[i]; 
            }else if(!result.empty()){
                st.push(result);
                result = "";
            }
        }
        if(!result.empty()){
            st.push(result);
        }
        result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
            if(!st.empty())
                result+='.';
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends