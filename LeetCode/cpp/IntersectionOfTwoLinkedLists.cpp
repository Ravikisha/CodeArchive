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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     unordered_set<ListNode*> uset;
    while(headA){
        uset.insert(headA);
        headA = headA->next;
    }
    while(headB){
        if(uset.find(headB) != uset.end()){
            return headB;
        }
        headB = headB->next;
    }
    return nullptr;   
    }
};