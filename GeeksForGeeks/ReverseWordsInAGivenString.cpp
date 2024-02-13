//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        vector<string> st;
        stringstream ss(S);
        string word;

        while (!ss.eof())
        {
            getline(ss, word, '.');
            st.push_back(word);
        }
        reverse(st.begin(), st.end());
        string s = std::accumulate(std::begin(st), std::end(st), string(),
                                   [](string &ss, string &s)
                                   {
                                       return ss.empty() ? s : ss + "." + s;
                                   });
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends