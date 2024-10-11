class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    int get(int key)
    {
        // If the key is not present in the cache, return -1.
        // If the key is present in the cache, return the value of the key. and update the key to the head of the cache.
        if (m.find(key) != m.end())
        {
            node *resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deletenode(resnode);
            addnode(resnode);
            m[key] = head->next;
            return res;
        }

        return -1;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void put(int key, int value)
    {
        // If the key is already present in the cache, update the value of the key and update the key to the head of the cache.
        if (m.find(key) != m.end())
        {
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        // If the key is not present in the cache, add the key to the head of the cache. 
        // If the cache is full, remove the key from the tail of the cache.
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */