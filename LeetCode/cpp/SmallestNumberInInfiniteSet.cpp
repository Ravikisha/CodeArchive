class SmallestInfiniteSet
{
    // Time Complexity: O(logn) for popSmallest, O(1) for addBack
    // Space Complexity: O(n) for minHeap and added set
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> added; // Track numbers in minHeap
    int count = 1;

    SmallestInfiniteSet() {}

    int popSmallest()
    {
        if (!minHeap.empty() && minHeap.top() < count)
        {
            int val = minHeap.top();
            minHeap.pop();
            added.erase(val); // Remove from added set
            return val;
        }
        return count++;
    }

    void addBack(int num)
    {
        if (num >= count || added.count(num))
            return; // Avoid duplicates
        minHeap.push(num);
        added.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */