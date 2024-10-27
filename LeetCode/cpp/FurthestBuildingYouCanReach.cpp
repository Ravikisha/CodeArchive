// Using Binary Search
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();

        int low = 0;
        int high = n;

        auto check = [&](int p) -> bool
        {
            int rem_brick = bricks;
            vector<int> need;

            for (int i = 0; i < p; i++)
            {
                if (heights[i + 1] > heights[i])
                    need.push_back(heights[i + 1] - heights[i]);
            }

            sort(need.begin(), need.end(), [](int a, int b)
                 { return a > b; });

            while (need.size() and rem_brick >= need.back())
            {
                rem_brick -= need.back();
                need.pop_back();
            }

            return ladders >= need.size();
        };

        while (low < high - 1)
        {
            int mid = low + (high - low) / 2;

            if (check(mid))
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};

// Using Priority Queue
class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < heights.size() - 1; ++i)
        {
            int diff = heights[i + 1] - heights[i];

            // Only consider jumps to taller buildings
            if (diff > 0)
            {
                minHeap.push(diff);

                // If the heap size exceeds the number of ladders, use bricks for the smallest jump
                if (minHeap.size() > ladders)
                {
                    bricks -= minHeap.top();
                    minHeap.pop();
                }

                // If bricks run out, return the current index
                if (bricks < 0)
                {
                    return i;
                }
            }
        }
        // If we reach here, we can reach the last building
        return heights.size() - 1;
    }
};