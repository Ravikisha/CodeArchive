struct Node
{
    string val;
    Node *next;
    Node *prev;
    Node(string val, Node *next, Node *prev)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};
class BrowserHistory
{
public:
    Node *head = nullptr;
    // Time: O(1)
    BrowserHistory(string homepage)
    {
        head = new Node(homepage, nullptr, nullptr);
    }

    // Time: O(1)
    void visit(string url)
    {
        Node *newNode = new Node(url, nullptr, nullptr);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        head->next = newNode;
        newNode->prev = head;
        head = newNode;
    }

    // Time: O(steps)
    string back(int steps)
    {
        int idx = 0;
        while (head->prev != nullptr && idx < steps)
        {
            head = head->prev;
            idx++;
        }
        return head->val;
    }

    // Time: O(steps)
    string forward(int steps)
    {
        int idx = 0;
        while (head->next != nullptr && idx < steps)
        {
            head = head->next;
            idx++;
        }
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */