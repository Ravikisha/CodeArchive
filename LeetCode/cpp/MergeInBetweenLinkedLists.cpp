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
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = nullptr;  // Node just before the 'a' position
        ListNode* afterB = nullptr; // Node just after the 'b' position
        
        ListNode* current = list1;
        int i = 0;

        // Find the node before position 'a' and the node after position 'b'
        while (current) {
            if (i == a - 1) {
                prevA = current;
            }
            if (i == b + 1) {
                afterB = current;
                break;
            }
            current = current->next;
            i++;
        }

        // Connect prevA's next to the head of list2
        prevA->next = list2;

        // Traverse to the end of list2
        while (list2->next) {
            list2 = list2->next;
        }

        // Connect the end of list2 to afterB
        list2->next = afterB;

        return list1;
    }
};