//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

// } Driver Code Ends
/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* Should return true if linked list is circular, else false */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isCircular(Node *head)
    {
        if (!head)
            return true;
        Node *slow = head;
        Node *fast = head->next;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main()
{
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--)
    {
        cin >> k;
        cin.ignore(); // Ignore the newline character after k

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x)
        {
            head = new Node(x);
            tail = head;

            while (ss >> x)
            {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1)
            {
                tail->next = head;
            }
        }

        Solution obj;
        cout << (obj.isCircular(head) ? "true" : "false") << endl;
    }
    return 0;
}

// } Driver Code Ends