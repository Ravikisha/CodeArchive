//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = prev = NULL;
    }
};

// } Driver Code Ends
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution
{
    // Time Complexity: O(N)
    // Space Complexity: O(1)
public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data)
    {
        Node *new_node = new Node(data);

        // Insertion at the beginning
        if (pos == 0)
        {
            new_node->next = head;

            // If the linked list is not empty, set the prev of head to new node
            if (head != NULL)
                head->prev = new_node;

            // Set the new node as the head of linked list
            head = new_node;
            return head;
        }

        Node *curr = head;
        // Traverse the list to find the node before the
        // insertion point
        for (int i = 1; i <= pos && curr != NULL; ++i)
        {
            curr = curr->next;
        }

        // If the position is out of bounds
        if (curr == NULL)
        {
            delete new_node;
            return head;
        }

        // Set the prev of new node to curr
        new_node->prev = curr;

        // Set the new of new node to next of curr
        new_node->next = curr->next;

        // Update the next of current node to new node
        curr->next = new_node;

        // If the new node is not the last node, update prev of next node to new node
        if (new_node->next != NULL)
            new_node->next->prev = new_node;

        // Return the head of the doubly linked list
        return head;
    }
};

//{ Driver Code Starts.

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);

    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
    // The purpose of below two loops is
    // to test the created DLL
    Node *temp = head;
    if (temp != NULL)
    {
        int ct1 = 0, ct2 = 0;
        while (temp->next != NULL)
            temp = temp->next, ct1++;
        while (temp->prev != NULL)
            temp = temp->prev, ct2++;
        if (ct1 != ct2)
        {
            cout << -1 << "\n";
            return;
        }
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after reading T to use getline properly

    while (t--)
    {
        Node *head = NULL;
        Node *root = NULL;
        vector<int> arr;
        string input;
        getline(cin, input);    // Read the entire line as input
        stringstream ss(input); // Use stringstream to split the input into integers
        int number;
        while (ss >> number)
        {
            arr.push_back(number); // Add each number to the vector
        }
        if (arr.empty())
        {
            return NULL; // Return NULL if the vector is empty
        }
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            head = insert(head, x);
            if (root == NULL)
                root = head;
        }
        head = root;
        int pos, data;
        cin >> pos >> data;
        cin.ignore();
        Solution ob;
        head = ob.addNode(head, pos, data);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends