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
public:
    ListNode* removeNodes(ListNode* head) {
        vector<ListNode *> stk;
        for (; head; head = head->next) {
            while (!empty(stk) && stk.back()->val < head->val) {
                stk.pop_back();
            }
            if (!empty(stk)) {
                stk.back()->next = head;
            }
            stk.emplace_back(head);
        }
        return stk[0];
    }
};