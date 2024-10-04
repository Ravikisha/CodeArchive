class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> uset;
        for (const string &email : emails)
        {
            string localName = email.substr(0, email.find("+"));
            if (localName == email)
                localName = email.substr(0, email.find("@"));
            string domainName = email.substr(email.find('@'), email.size());
            while (true)
            {
                int dot = localName.find(".");
                if (dot == -1)
                    break;
                else
                    localName.erase(dot, 1);
            }
            uset.insert(localName + domainName);
        }
        return uset.size();
    }
};