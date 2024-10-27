class MyHashSet
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)

    // Worst case
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int capacity;
    int size;
    vector<int> s;
    float load_factor;
    MyHashSet()
    {
        capacity = 8;
        size = 0;
        s = vector<int>(capacity, -1);
        load_factor = 2.0f / 3.0f;
    }

    int hash(int key) { return key % capacity; }
    int rehash(int key) { return (key * 5 + 1) % capacity; }

    void add(int key)
    {
        if (float(size) / capacity >= load_factor)
        {
            capacity <<= 1;
            vector<int> ns(capacity, -1);
            for (int i = 0; i < capacity >> 1; i++)
            {
                if (s[i] >= 0)
                {
                    int pos = hash(s[i]);
                    while (ns[pos] != -1)
                    {
                        pos = rehash(pos);
                    }
                    ns[pos] = s[i];
                }
            }
            s = ns;
        }
        int pos = hash(key);
        while (s[pos] >= 0)
        {
            if (s[pos] == key)
                return;
            pos = rehash(pos);
        }
        s[pos] = key;
        ++size;
    }

    void remove(int key)
    {
        int pos = hash(key);
        while (s[pos] != -1)
        {
            if (s[pos] == key)
            {
                s[pos] = -2;
                --size;
                break;
            }
            pos = rehash(pos);
        }
    }

    bool contains(int key)
    {
        int pos = hash(key);
        while (s[pos] != -1)
        {
            if (s[pos] == key)
                return true;
            pos = rehash(pos);
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */