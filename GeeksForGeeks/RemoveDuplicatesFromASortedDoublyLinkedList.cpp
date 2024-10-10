//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *newNode(int data)
{
    Node *temp = new Node(data);

    return temp;
}

void displayList(Node *head)
{
    // Head to Tail
    while (head->next)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

int getLength(Node *head)
{
    Node *temp = head;

    int count = 0;
    while (temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}

bool verify(Node *head)
{
    int fl = 0;
    int bl = 0;

    Node *temp = head;

    while (temp->next)
    {
        temp = temp->next;
        fl++;
    }

    while (temp->prev)
    {
        temp = temp->prev;
        bl++;
    }

    return fl == bl;
}

// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    Node *removeDuplicates(struct Node *head)
    {
        if (head == NULL)
            return head; // If the list is empty, return

        Node *curr = head;

        // Traverse the list
        while (curr != NULL && curr->next != NULL)
        {
            // If the current node's data is the same as the next node's data
            if (curr->data == curr->next->data)
            {
                Node *duplicate = curr->next;
                // Skip the duplicate node
                curr->next = duplicate->next;
                if (duplicate->next != NULL)
                {
                    duplicate->next->prev = curr;
                }
                // Delete the duplicate node
                delete duplicate;
            }
            else
            {
                // Move to the next node if no duplicate is found
                curr = curr->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = newNode(x);
        tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            Node *temp = newNode(x);
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        Solution obj;
        head = obj.removeDuplicates(head);

        if (verify(head))
            displayList(head);
        else
            cout << "Your pointers are not correctly connected";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends