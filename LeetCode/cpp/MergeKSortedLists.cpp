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

class Compare
{
public:
    bool operator()(const ListNode *below, const ListNode *above)
    {
        return below->val > above->val; // Min-heap: smallest element at top
    }
};
class Solution
{
    // Time Complexity: O(NlogK)
    // Space Complexity: O(K)
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        // Push the head of each non-empty list into the minHeap
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != nullptr)
            {
                minHeap.push(lists[i]);
            }
        }

        // Merge the nodes
        while (!minHeap.empty())
        {
            ListNode *topValue = minHeap.top();
            minHeap.pop();

            temp->next = topValue; // Attach the node with smallest value
            temp = temp->next;     // Move the temp pointer forward

            if (topValue->next != nullptr)
            {
                minHeap.push(
                    topValue->next); // Push the next node in the same list
            }
        }

        return dummy->next; // Return merged list starting from dummy->next
    }
};