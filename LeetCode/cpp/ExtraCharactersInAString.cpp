struct Node
{
    Node *links[26];
    bool flag;
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node *node) { links[ch - 'a'] = node; }
    Node *get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};
class Trie
{
public:
    Node *root;
    Trie() { root = new Node(); }

    // Time Complexity: O(n)
    // Space Complexity: O(n)
    void insert(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    bool search(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    bool startsWith(string prefix)
    {
        Node *node = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++)
        {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        Trie *trie = new Trie();

        // Insert all words from dictionary into the trie
        for (string word : dictionary)
        {
            trie->insert(word);
        }

        int n = s.size();
        vector<int> dp(n + 1, n); // Initialize DP array with max possible extra chars (n)
        dp[0] = 0;                // No extra chars for an empty string

        // Populate the DP array
        for (int i = 0; i < n; i++)
        {
            // If current dp[i] has some extra characters, continue checking
            dp[i + 1] = min(dp[i + 1], dp[i] + 1); // Count `s[i]` as an extra character by default

            Node *node = trie->root;
            for (int j = i; j < n; j++)
            {
                if (!node->containsKey(s[j]))
                    break; // No match, exit inner loop

                node = node->get(s[j]);
                if (node->isEnd())
                {
                    dp[j + 1] = min(dp[j + 1], dp[i]); // Update DP if word found in Trie
                }
            }
        }

        return dp[n]; // Minimum extra chars needed for entire string `s`
    }
};