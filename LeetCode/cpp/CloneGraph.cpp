/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> oldToNew;
        if (!node)
            return NULL;

        function<Node *(Node *)> dfs = [&](Node *node)
        {
            if (oldToNew[node])
                return oldToNew[node];
            Node *copy = new Node(node->val);
            oldToNew[node] = copy;
            for (Node *neighbor : node->neighbors)
            {
                copy->neighbors.push_back(dfs(neighbor));
            }
            return copy;
        };
        return dfs(node);
    }
};