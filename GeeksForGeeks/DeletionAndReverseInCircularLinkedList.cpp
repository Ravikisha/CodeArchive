//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head)
{
    if (head != NULL)
    {
        struct Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        cout << "empty" << endl;
    }
    cout << endl;
}

// } Driver Code Ends
class Solution
{
public:
    // Function to reverse a circular linked list
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    Node *reverse(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *prev = nullptr;
        Node *curr = head;
        Node *next;
        do
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);

        // The original head should point to the new first element (which is prev)
        head->next = prev; // This makes the old head point to the new head
        head = prev;       // Update the head pointer to point to the new head

        return head;
    }

    // Function to delete a node from the circular linked list
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    Node *deleteNode(Node *head, int key)
    {
        Node *temp = head->next, *prev = head;
        if (head->data == key)
        {
            while (temp != head)
            {
                prev = temp;
                temp = temp->next;
            }
        }
        else
        {
            while (temp != head and temp->data != key)
            {
                prev = temp;
                temp = temp->next;
            }
        }
        if (head->data == key or temp != head)
            prev->next = temp->next;
        return head->data == key ? prev->next : head;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Reading input into a vector
        while (ss >> number)
        {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends