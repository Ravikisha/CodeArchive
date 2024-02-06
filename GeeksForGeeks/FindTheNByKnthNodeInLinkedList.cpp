//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}

// } Driver Code Ends


/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
int fractional_node(struct Node *head, int k)
{
    struct Node* temp = head;
    int i=0;
    Node* fractionalNode = NULL;
     
    // Traverse the given list
    for (Node* temp = head; temp != NULL; temp = temp->next) {
 
        // For every k nodes, we move fractionalNode one
        // step ahead.

        /*
            In the first iteration, i = 0, so the condition is true, and the fractionalNode is set to head.
            In the following iterations, i is incremented by 1, and the condition is checked again. If the condition is true, the fractionalNode is set to the next node.
            This way, the fractionalNode is set to the kth node, the 2kth node, the 3kth node, and so on.

            n = 15
            list = 88 57 44 92 28 66 60 37 33 52 38 29 76 8 75 
             k = 2

            i = 0, k = 2, fractionalNode = 88, temp = 57
            i = 1, k = 2, fractionalNode = 88, temp = 44
            i = 2, k = 2, fractionalNode = 57, temp = 92
            i = 3, k = 2, fractionalNode = 57, temp = 28
            i = 4, k = 2, fractionalNode = 44, temp = 66
            i = 5, k = 2, fractionalNode = 44, temp = 60
            i = 6, k = 2, fractionalNode = 92, temp = 37
            i = 7, k = 2, fractionalNode = 92, temp = 33
            i = 8, k = 2, fractionalNode = 28, temp = 52
            i = 9, k = 2, fractionalNode = 28, temp = 38
            i = 10, k = 2, fractionalNode = 66, temp = 29
            i = 11, k = 2, fractionalNode = 66, temp = 76
            i = 12, k = 2, fractionalNode = 60, temp = 8
            i = 13, k = 2, fractionalNode = 60, temp = 75
            i = 14, k = 2, fractionalNode = 37, temp = NULL

        */
        
        if (i % k == 0) {
 
            // First time we see a multiple of k
            if (fractionalNode == NULL)
                fractionalNode = head;
 
            else
                fractionalNode = fractionalNode->next;
        }
        i++;
    }
    return fractionalNode->data;
}
