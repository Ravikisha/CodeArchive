#include <bits/stdc++.h>
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

// Time Complexity: O(n)
// Space Complexity: O(n)
Node *removeDuplicates(Node *head)
{
    unordered_set<int> hashSet;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end())
        {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}