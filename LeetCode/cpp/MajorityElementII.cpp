class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counter;

        for (int &num : nums)
        {
            ++counter[num];
        }

        vector<int> ans;
        int n = nums.size();

        for (auto it = counter.begin(); it != counter.end(); ++it)
        {
            if (it->second > n / 3)
            {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};

// Optimal Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Boyer-Moore Voting Algorithm
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // As we need to find the majority element which appears more than n/3 times
        // There can be at most 2 majority elements

        // Initialize two variables to store the majority elements
        int a = INT_MIN, b = INT_MIN;
        // Initialize two variables to store the count of the majority elements
        int acounter = 0, bcounter = 0;

        int n = nums.size();

        for (int &num : nums)
        {
            // If the current number is equal to a or b, increment the count of the respective number
            // If the count of a or b is 0, then update the respective number
            // If the current number is not equal to a or b, decrement the count of a and b
            if (num == a)
            {
                ++acounter;
            }
            else if (num == b)
            {
                ++bcounter;
            }
            else if (acounter == 0)
            {
                a = num;
                ++acounter;
            }
            else if (bcounter == 0)
            {
                b = num;
                ++bcounter;
            }
            else if (num != a && num != b)
            {
                --acounter;
                --bcounter;
            }
        }

        // Reset the count of a and b
        acounter = bcounter = 0;
        // Count the number of times a and b appear in the array
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == a)
                ++acounter;
            if (nums[i] == b)
                ++bcounter;
        }

        // If the count of a or b is greater than n/3, then add it to the answer
        vector<int> ans;

        if (acounter > n / 3)
            ans.push_back(a);
        if (bcounter > n / 3)
            ans.push_back(b);

        return ans;
    }
};