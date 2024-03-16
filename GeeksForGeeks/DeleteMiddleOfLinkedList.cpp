//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Link list Node:

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

// Deletes middle of linked list and returns head of the modified list
class Solution{
    public:
    Node* deleteMid(Node* head)
    {
         Node *ptr=head;
    int count=0,pos=0;
    Node *ptr1=head;
    Node *temp2=NULL;
    while(ptr->next!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
        if(count%2!=0)
        {
          pos=(count+1)/2;  
        }
        else
        pos=count/2;
       ptr1=head;
              int i=1;
              while(i<pos)
              {
                  ptr1=ptr1->next;
                  i++;
              }
              
              temp2=ptr1->next;
              
             ptr1->next =temp2->next;
             delete(temp2);
    return head;
    }
};

//{ Driver Code Starts.



void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		Solution obj;
		head = obj.deleteMid(head);
		printList(head); 
	}
	return 0; 
} 



// } Driver Code Ends