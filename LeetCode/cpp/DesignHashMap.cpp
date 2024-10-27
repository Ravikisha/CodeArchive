class MyHashMap
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> keys;
    vector<int> values;
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if (it != keys.end())
        {
            values[(it - keys.begin())] = value;
        }
        else
        {
            keys.push_back(key);
            values.push_back(value);
        }
    }

    int get(int key)
    {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if (it == keys.end())
        {
            return -1;
        }
        else
        {
            return values[it - keys.begin()];
        }
    }

    void remove(int key)
    {
        vector<int>::iterator it = find(keys.begin(), keys.end(), key);
        if (it != keys.end())
        {
            keys.erase(it);
            values.erase(values.begin() + (it - keys.begin()));
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// Using Hashing (Chaining)
struct Node
{
public:
    int key, val;
    Node *next;
    Node(int k, int v, Node *n)
    {
        key = k;
        val = v;
        next = n;
    }
};
class MyHashMap
{
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node *data[size] = {};
    int hash(int key) { return (int)((long)key * mult % size); }
    void put(int key, int val)
    {
        remove(key);
        int h = hash(key);
        Node *node = new Node(key, val, data[h]);
        data[h] = node;
    }
    int get(int key)
    {
        int h = hash(key);
        Node *node = data[h];
        for (; node != NULL; node = node->next)
            if (node->key == key)
                return node->val;
        return -1;
    }
    void remove(int key)
    {
        int h = hash(key);
        Node *node = data[h];
        if (node == NULL)
            return;
        if (node->key == key)
        {
            data[h] = node->next;
            delete node;
        }
        else
            for (; node->next != NULL; node = node->next)
                if (node->next->key == key)
                {
                    Node *temp = node->next;
                    node->next = temp->next;
                    delete temp;
                    return;
                }
    }
};
