//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    Node *reverse(Node *head)
    {
        // reverse the later part of original list
        Node *prev = NULL;
        Node *tmp;
        while (head != NULL)
        {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        // when the loop finishes, head is NULL,
        // and prev is the last node in the original list
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL)
        {
            // the length of list is odd
            // in this situation we should ignore the middle node
            slow = slow->next;
        }

        // slow: later part of original list
        // fast: former part of original list
        slow = reverse(slow);
        fast = head;

        while (slow != NULL)
        {
            if (slow->data != fast->data)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};

//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }

        if (arr.empty())
        {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL)
        {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends