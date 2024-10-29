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
class WordDictionary
{
private:
    Node *root;

public:
    WordDictionary() { root = new Node(); }

    void addWord(string word)
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
    
    // Time Complexity: O(26^n)
    // Space Complexity: O(n)
    bool search(string word)
    {
        int n = word.size();
        function<bool(int, Node *)> dfs = [&](int j, Node *node)
        {
            if (node == nullptr)
                return false; // Add null check for node

            for (int i = j; i < n; i++)
            {
                char c = word[i];
                if (c == '.')
                {
                    // Explore all possible links for wildcard '.'
                    for (int k = 0; k < 26; k++)
                    {
                        if (node->links[k] != nullptr && dfs(i + 1, node->links[k])) // Null check for node->links[k]
                            return true;
                    }
                    return false; // If no path matches, return false
                }
                else
                {
                    if (!node->containsKey(c))
                        return false; // Return false if path doesn't exist
                    node = node->get(c);
                }
            }
            return node->isEnd(); // Check if this path is a valid end of a word
        };
        return dfs(0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */