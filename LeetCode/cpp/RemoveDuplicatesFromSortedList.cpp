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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        while(cur != NULL ){
            
            if(cur->val == prev->val){
                prev->next=cur->next;
            }else{
                prev = cur;
            }
            cur = cur->next;
        }
        return head;

    }
};