class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y > x)
            {
                pq.push(y - x);
            }
        }

        if (pq.empty())
        {
            return 0;
        }
        return pq.top();
    }
};

// Solution using ranges
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int lastStoneWeight(vector<int> &stones)
    {
        ranges::make_heap(stones);
        while (stones.size() >= 2)
        {
            ranges::pop_heap(stones);
            int x = stones.back();
            stones.pop_back();

            ranges::pop_heap(stones);
            int &y = stones.back();

            y = abs(x - y);
            if (y != 0)
            {
                ranges::push_heap(stones);
            }
            else
            {
                stones.pop_back();
            }
        }

        return stones.empty() ? 0 : stones.front();
    }
};