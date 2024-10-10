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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        int n = 1;
        ListNode *curr = head;
        for (; curr->next; curr = curr->next)
        {
            ++n;
        }
        curr->next = head;

        ListNode *tail = curr;
        k = n - k % n;
        curr = head;
        for (int i = 0; i < k; curr = curr->next, ++i)
        {
            tail = curr;
        }

        tail->next = nullptr;
        return curr;
    }
};

/*
Explanation:
1. Find the length of the linked list and make it circular.
2. Find the new tail and the new head.
3. Break the circular list and return the new head.



*/