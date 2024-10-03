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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *curr = head;
        ListNode *prev = dummy;
        while (curr && curr->next)
        {
            ListNode *nextPair = curr->next->next;
            ListNode *second = curr->next;
            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            prev = curr;
            curr = nextPair;
        }
        return dummy->next;
    }
};

/*
Explaination:
1. Create a dummy node and point it to the head of the list.
2. Create a pointer to the dummy node and another pointer to the head of the list.
3. Traverse the list and swap the nodes in pairs.
4. Return the next of the dummy node.

Example:
Input: 1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3

Stage 1:
dummy -> 1 -> 2 -> 3 -> 4

Stage 2:
dummy -> 2 -> 1 -> 3 -> 4

Stage 3:
dummy -> 2 -> 1 -> 4 -> 3

*/