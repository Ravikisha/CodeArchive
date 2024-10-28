class MedianFinder
{
    // Time Complexity: O(logn) for addNum, O(1) for findMedian
    // Space Complexity: O(n)
public:
    priority_queue<float> maxHeap;                                // small values store
    priority_queue<float, vector<float>, greater<float>> minHeap; // larger values store
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        maxHeap.push(num);
        // make sure every num small is <= every num in large
        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        // uneven size
        if (maxHeap.size() > minHeap.size() + 1)
        {
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
        if (minHeap.size() > maxHeap.size() + 1)
        {
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }
    }

    double findMedian()
    {
        if (minHeap.size() > maxHeap.size())
            return minHeap.top();
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();
        return (minHeap.top() + maxHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */