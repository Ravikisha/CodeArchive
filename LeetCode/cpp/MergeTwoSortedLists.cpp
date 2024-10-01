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
    // Time Complexity: O(n+m)
    // Space Complexity: O(1)
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        // let the list with smaller head be cur1
        ListNode *h, *cur1, *cur2;
        if (list1->val <= list2->val)
        {
            h = cur1 = list1;
            cur2 = list2;
        }
        else
        {
            h = cur1 = list2;
            cur2 = list1;
        }
        if (cur1->next == NULL)
        {
            cur1->next = cur2;
            return cur1;
        }
        // stop when one of the list ends
        while (cur2 != NULL && cur1 != NULL)
        {
            // cout << cur1->val << " " << cur2->val << endl;
            if (cur1->next == NULL)
            {
                cur1->next = cur2;
                // done processing first list
                cur1 = NULL;
            }
            else if (cur2->val <= cur1->next->val)
            {
                // merge cur2 into l1 and move cur2
                ListNode *tmp = cur1->next;
                cur1->next = cur2;
                cur2 = cur2->next;
                cur1->next->next = tmp;
            }
            else
            {
                // move cur1 to the next
                cur1 = cur1->next;
            }
        }
        return h;
    }
};

/*
Explanation:
1. If any of the list is NULL, return the other list.
2. Let the list with smaller head be cur1.
3. If cur1->next is NULL, merge cur2 into cur1 and return cur1.
4. Stop when one of the list ends.
5. If cur1->next is NULL, merge cur2 into cur1 and return cur1.
6. If cur2->val <= cur1->next->val, merge cur2 into cur1 and move cur2.
7. Else, move cur1 to the next.
8. Return the head.
*/