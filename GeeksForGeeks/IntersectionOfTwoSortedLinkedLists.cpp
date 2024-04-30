//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    if (n)
        while (n)
        {
            cout << n->data << " ";
            n = n->next;
        }
    else
        cout << " ";
}

// } Driver Code Ends
/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        Node *result = nullptr;
        Node *curr = nullptr;

        unordered_map<int, int> set;
        while (head1 != nullptr)
        {
            set[head1->data] = set[head1->data] + 1;
            head1 = head1->next;
        }

        while (head2 != nullptr)
        {
            if (set.find(head2->data) != set.end() && set[head2->data] > 0)
            {
                set[head2->data] = set[head2->data] - 1;
                if (result == nullptr)
                {
                    result = new Node(head2->data);
                    curr = result;
                }
                else
                {
                    curr->next = new Node(head2->data);
                    curr = curr->next;
                }
            }
            head2 = head2->next;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Solution ob;
        Node *result = ob.findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends