class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        if (m > n)
            return {};

        unordered_map<char, int> sCounter;
        unordered_map<char, int> pCounter;
        vector<int> result;

        for (int i = 0; i < m; i++)
        {
            pCounter[p[i]]++;
        }

        for (int i = 0; i < m; i++)
        {
            sCounter[s[i]]++;
        }
        if (sCounter == pCounter)
            result.push_back(0);

        int l = m, r = m;
        for (int i = m; i < n; i++)
        {
            sCounter[s[i]]++;

            char leftChar = s[i - m];
            sCounter[leftChar]--;
            if (sCounter[leftChar] == 0)
            {
                sCounter.erase(leftChar);
            }

            if (sCounter == pCounter)
                result.push_back(i - m + 1);
        }

        return result;
    }
};