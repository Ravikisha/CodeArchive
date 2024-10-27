class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> result;

        // Add indices to tasks for tracking original order
        vector<tuple<int, int, int>> tasksWithIndex;
        for (int i = 0; i < n; ++i)
        {
            tasksWithIndex.emplace_back(tasks[i][0], tasks[i][1], i);
        }

        // Sort tasks by their enqueue time
        sort(tasksWithIndex.begin(), tasksWithIndex.end());

        // Min-heap to select the next task with the smallest processing time (or smallest index in tie)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        int i = 0;
        long long currentTime = 0;

        while (i < n || !minHeap.empty())
        {
            // Push all tasks that can be processed by the current time into the heap
            while (i < n && get<0>(tasksWithIndex[i]) <= currentTime)
            {
                minHeap.emplace(get<1>(tasksWithIndex[i]), get<2>(tasksWithIndex[i]));
                ++i;
            }

            if (minHeap.empty())
            {
                // If no tasks are available, skip time to the next task's enqueue time
                currentTime = get<0>(tasksWithIndex[i]);
            }
            else
            {
                // Process the next task in the minHeap
                auto [processTime, index] = minHeap.top();
                minHeap.pop();

                currentTime += processTime;
                result.push_back(index);
            }
        }

        return result;
    }
};