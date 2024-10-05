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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            // If the list is empty or has only one element, return NULL
            return NULL;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr; // To track the node before the middle

        // Use slow and fast pointers to find the middle
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow; // prev will point to the node before slow
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now, slow is the middle node, and prev is the node before the middle
        if (prev != nullptr)
        {
            prev->next = slow->next; // Skip the middle node
        }

        delete slow; // Free the memory of the middle node

        return head;
    }
};