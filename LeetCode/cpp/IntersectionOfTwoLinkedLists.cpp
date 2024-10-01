/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> uset;
        while (headA)
        {
            uset.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (uset.find(headB) != uset.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

// Optimal Approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int init = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        // Traverse both lists. Once one pointer reaches the end, switch it to the other list's head.
        // This allows the two pointers to be aligned after one full cycle.
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        // If a and b intersect, they will be equal at some point, otherwise both will be null.
        return a;
    }
};

/*
Explaination:
1. Traverse both lists. Once one pointer reaches the end, switch it to the other list's head.
2. This allows the two pointers to be aligned after one full cycle.
3. If a and b intersect, they will be equal at some point, otherwise both will be null.

Example:
headA = [4,1,8,4,5], headB = [5,6,1,8,4,5]
Iterate over both lists:
a = 4 -> 1 -> 8 -> 4 -> 5 -> 5 -> 6 -> 1 -> 8
b = 5 -> 6 -> 1 -> 8 -> 4 -> 5 -> 4 -> 1 -> 8

matched at 8
*/