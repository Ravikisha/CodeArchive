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
    // Time Complexity: O(N + M)
    // Space Complexity: O(N)
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

// Optimal Solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
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

class Solution {
    // Time Complexity: O(N + M)
    // Space Complexity: O(1)
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        Node *head = NULL, *tail = NULL;
        while(head1 && head2){
            if(head1->data == head2->data){
                if(head == NULL){
                    head = tail = new Node(head1->data);
                }else{
                    tail->next = new Node(head1->data);
                    tail = tail->next;
                }
                head1 = head1->next;
                head2 = head2->next;
            }else if(head1->data > head2->data){
                head2 = head2->next;
            }else{
                head1 = head1->next;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *result = obj.findIntersection(head1, head2);

        printList(result);
        // cout << endl;
    }
    return 0;
}

// } Driver Code Ends