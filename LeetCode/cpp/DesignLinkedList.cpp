struct NodeList
{
    int data;
    NodeList *next;
    NodeList(int value, NodeList *next)
    {
        this->data = value;
        this->next = next;
    }
};
class MyLinkedList
{
public:
    NodeList *head;
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    MyLinkedList()
    {
        head = nullptr;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    int get(int index)
    {
        NodeList *temp = this->head;
        int idx = 0;
        while (temp != nullptr && idx < index)
        {
            temp = temp->next;
            idx++;
        }
        if (temp == nullptr)
            return -1;
        return temp->data;
    }

    // Time Complexity: O(1)
    // Space Complexity: O(1)
    void addAtHead(int val)
    {
        NodeList *newNode = new NodeList(val, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void addAtTail(int val)
    {
        NodeList *newNode = new NodeList(val, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        NodeList *temp = head;
        while (temp && temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        NodeList *newNode = new NodeList(val, nullptr);
        int idx = 0;
        NodeList *temp = head;
        while (temp != nullptr && idx < index - 1)
        {
            temp = temp->next;
            idx++;
        }
        if (temp == nullptr)
            return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Time Complexity: O(n)
    // Space Complexity: O(1)
    void deleteAtIndex(int index)
    {
        if (head == nullptr)
        {
            return;
        }
        if (index == 0)
        {
            NodeList *dis = head;
            head = head->next;
            delete dis;
            return;
        }
        int idx = 0;
        NodeList *temp = head;
        NodeList *prev = nullptr;
        while (temp != nullptr && idx < index)
        {
            prev = temp;
            temp = temp->next;
            idx++;
        }
        if (temp == nullptr)
            return;
        prev->next = temp->next;
        delete temp;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */