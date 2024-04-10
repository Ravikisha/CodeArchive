//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

#define MAX_SIZE 100
class twoStacks
{
public:
    int *arr;
    int top1;
    int top2;

    twoStacks()
    {
        arr = new int[MAX_SIZE];
        top1 = -1;
        top2 = MAX_SIZE;
    }

    // Function to push an integer into the stack1.
    void push1(int x)
    {
        top1++;
        arr[top1] = x;
    }

    // Function to push an integer into the stack2.
    void push2(int x)
    {
        top2--;
        arr[top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1()
    {
        int answer = -1;
        if (top1 != -1)
        {
            answer = arr[top1];
            top1--;
        }
        return answer;
    }

    // Function to remove an element from top of the stack2.
    int pop2()
    {
        int answer = -1;
        if (top2 != MAX_SIZE)
        {
            answer = arr[top2];
            top2++;
        }
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--)
        {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1)
            {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            }
            else if (QueryType == 2)
            {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends