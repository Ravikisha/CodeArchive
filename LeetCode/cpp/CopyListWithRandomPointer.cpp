/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> umap;
        umap[nullptr] = nullptr;
        Node *cur = head;
        while (cur != nullptr)
        {
            umap[cur] = new Node(cur->val, nullptr);
            cur = cur->next;
        }
        cur = head;
        Node *newList = nullptr;
        while (cur != nullptr)
        {
            newList = umap[cur];
            newList->next = umap[cur->next];
            newList->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }
};

/*
Explanation:
1. Create a map to store the mapping of original node to the new node.
2. Traverse the original list and create a new node for each node in the original list and store the mapping in the map.
3. Traverse the original list again and set the next and random pointers of the new nodes using the mapping stored in the map.
4. Return the head of the new list.
*/