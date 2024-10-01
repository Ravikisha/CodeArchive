/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    ListNode *removeNodes(ListNode *head)
    {
        vector<ListNode *> stk;
        for (; head; head = head->next)
        {
            while (!empty(stk) && stk.back()->val < head->val)
            {
                stk.pop_back();
            }
            if (!empty(stk))
            {
                stk.back()->next = head;
            }
            stk.emplace_back(head);
        }
        return stk[0];
    }
};

// Optimal Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *reversedHead = reverseList(head);
        ListNode *maxNode = reversedHead;
        ListNode *current = reversedHead->next;

        while (current)
        {
            if (current->val < maxNode->val)
            {
                maxNode->next = current->next; // Remove current node
            }
            else
            {
                maxNode = current; // Update maxNode if current has a larger value
            }
            current = current->next;
        }

        return reverseList(reversedHead); // Reverse the list back to original order
    }
};