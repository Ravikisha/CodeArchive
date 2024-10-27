class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n)
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks)
    {
        vector<int> result(tasks.size());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            available;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            unavailable;
        for (int i = 0; i < servers.size(); i++)
        {
            available.push(make_pair(servers[i], i));
        }
        int time = 0;

        for (int i = 0; i < tasks.size(); i++)
        {
            time = max(time, i);
            while (!unavailable.empty() && time >= get<0>(unavailable.top()))
            {
                auto [timeFree, weight, index] = unavailable.top();
                unavailable.pop();
                available.emplace(make_pair(weight, index));
            }
            if (available.empty())
            {
                time = get<0>(unavailable.top());
                while (!unavailable.empty() &&
                       get<0>(unavailable.top()) <= time)
                {
                    auto [timeFree, weight, index] = unavailable.top();
                    unavailable.pop();
                    available.emplace(weight, index);
                }
            }
            auto [weight, index] = available.top();
            available.pop();
            result[i] = index;
            unavailable.emplace(make_tuple(time + tasks[i], weight, index));
        }
        return result;
    }
};