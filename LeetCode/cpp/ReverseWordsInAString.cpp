class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    string reverseWords(string s)
    {
        stack<string> sstack;
        string temp = "", ans = "";
        // temp is useed to store each word in st

        // use the stack to store words
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' && temp != "")
            {
                sstack.push(temp);
                temp = "";
            }
            // ignore spaces
            else if (s[i] == ' ' && temp == "")
                continue;
            else
                temp += s[i];
        }
        if (temp != "")
            sstack.push(temp);

        // pop the stack and store the words in ans
        s = "";
        while (!sstack.empty())
        {
            string temp = sstack.top();
            s += temp;
            sstack.pop();
            if (!sstack.empty())
                s += " ";
        }
        return s;
    }
};