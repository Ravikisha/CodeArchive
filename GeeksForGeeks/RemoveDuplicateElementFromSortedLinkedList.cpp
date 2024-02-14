//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *removeDuplicates(Node *root);
int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Node *result = removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *p = head; // point to prenode
    int preVal = head->data;
    while (p->next != NULL)
    {
        if (p->next->data == preVal)
        {
            // remove the node
            Node *pp = p->next;
            p->next = pp->next;
            delete pp; // no need to move forward. Already delete a node
        }
        else
        {
            preVal = p->next->data;
            p = p->next; // move forward
        }
    }
    return head;
}