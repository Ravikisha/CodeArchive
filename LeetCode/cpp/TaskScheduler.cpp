class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        /*
        Different Approach (Time Limit Exceed)

        unordered_map<char, int> counter;
        for(int i=0;i<tasks.size();i++){
            if(counter[tasks[i]]){
                counter[tasks[i]]++;
            }
        }
        priority_queue<int> maxHeap;
        for(auto iter: counter) {
            maxHeap.push(iter.second);
        }
        queue<pair<int, int>> eventQueue;
        int time = 0;
        while(!maxHeap.empty() || !eventQueue.empty()){
            time++;
            if(!maxHeap.empty()){
                int count = maxHeap.top()-1;maxHeap.pop();
                if(count)
                    eventQueue.push(make_pair(count, time+n));
            }
            if(!eventQueue.empty() && eventQueue.front().second == time){
                maxHeap.push(eventQueue.front().first);
            }
        }
        return time;
        */
        unordered_map<char, int> counter;
        int max_freq = 0, max_count = 0;

        // Count the frequency of each task
        for (char task : tasks)
        {
            counter[task]++;
            if (counter[task] > max_freq)
            {
                max_freq = counter[task];
                max_count = 1;
            }
            else if (counter[task] == max_freq)
            {
                max_count++;
            }
        }

        // Calculate the minimum intervals needed
        int intervals = max((int)tasks.size(), (max_freq - 1) * (n + 1) + max_count);
        return intervals;
    }
};