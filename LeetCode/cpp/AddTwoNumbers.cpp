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
    // Time Complexity: O(max(n,m))
    // Space Complexity: O(max(n,m))
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, sum = 0;
        ListNode *head = NULL, *tail = NULL;
        while (l1 != NULL || l2 != NULL)
        {
            sum = carry;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode *temp = new ListNode(sum);
            if (head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
        if (carry != 0)
        {
            ListNode *temp = new ListNode(carry);
            tail->next = temp;
            tail = temp;
        }
        return head;
    }
};

// More Cleaner Solution
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
    // Time Complexity: O(max(n,m))
    // Space Complexity: O(max(n,m))
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0); // Dummy node to simplify list management
        ListNode *current = dummy;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = carry;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next; // Return the head of the new list
    }
};