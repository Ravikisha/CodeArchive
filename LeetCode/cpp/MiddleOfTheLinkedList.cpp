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
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
class Solution {
public:
    Solution(){
        fastio;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};