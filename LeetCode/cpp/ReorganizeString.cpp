class Solution
{
    // Time Complexity: O(NlogA), where N is the length of the string and A is the size of the alphabet (26 in this case) 
    // Space Complexity: O(A), where A is the size of the alphabet (26 in this case)
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> umap;
        for (char c : s)
            umap[c]++;

        priority_queue<pair<int, char>> maxHeap;
        for (const auto &it : umap)
        {
            maxHeap.push(make_pair(it.second, it.first));
        }

        pair<int, char> prev = {-1, ' '}; // Initialize prev as "empty"
        string result;

        while (!maxHeap.empty())
        {
            auto [count, character] = maxHeap.top();
            maxHeap.pop();
            result += character;
            count -= 1;

            // Push the previous character back to the heap if it has remaining
            // counts
            if (prev.first > 0)
            {
                maxHeap.push(prev);
            }

            // Set the current character as prev if it has remaining counts
            prev =
                (count > 0) ? make_pair(count, character) : make_pair(-1, ' ');
        }

        return (result.size() == s.size()) ? result : "";
    }
};