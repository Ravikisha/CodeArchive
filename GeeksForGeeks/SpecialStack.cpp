//{ Driver Code Starts
#include <iostream>
#include <stack>
using namespace std;
void push(stack<int> &s, int a);
bool isFull(stack<int> &s, int n);
bool isEmpty(stack<int> &s);
int pop(stack<int> &s);
int getMin(stack<int> &s);
// This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n;
        while (!isEmpty(s))
        {
            pop(s);
        }
        while (!isFull(s, n))
        {
            cin >> a;
            push(s, a);
        }
        cout << getMin(s) << endl;
    }
}
// } Driver Code Ends

void push(stack<int> &s, int a)
{
    s.push(a);
}

bool isFull(stack<int> &s, int n)
{
    if (s.size() == n)
        return true;
    else
        return false;
}

bool isEmpty(stack<int> &s)
{
    return s.empty();
}

int pop(stack<int> &s)
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        return x;
    }
    else
        return -1;
}

int getMin(stack<int> &s)
{
    int min = s.top();
    s.pop();
    while (!s.empty())
    {
        if (min > s.top())
        {
            min = s.top();
        }
        s.pop();
    }
    return min;
}