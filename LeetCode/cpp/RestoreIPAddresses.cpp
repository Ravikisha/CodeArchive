class Solution
{
    // Time Complexity: O(3^4) or O(1) Actually the max height = 5
    // Space Complexity: O(3^4) or O(1) Actually the max height = 5
    // These are constant cause of the characters has only 12 options
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        int n = s.size();
        if (s.size() > 12)
            return result;

        function<void(int, int, string)> backtrack = [&](int i, int dots,
                                                         string currIP)
        {
            if (dots == 4 && i == n)
            {
                result.push_back(currIP.substr(0, currIP.size() - 1));
                return;
            }
            if (dots > 4)
                return;
            for (int j = i; j < min(i + 3, n); j++)
            {
                if (stoi(s.substr(i, j - i + 1)) <= 255 &&
                    (i == j || s[i] != '0'))
                {
                    backtrack(j + 1, dots + 1,
                              currIP + s.substr(i, j - i + 1) + ".");
                }
            }
        };
        backtrack(0, 0, "");
        return result;
    }
};