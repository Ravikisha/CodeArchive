class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for (const auto& str : strs) {
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while (i < s.size()) {
            int delimiter = s.find('#', i);
            if (delimiter == string::npos) break;

            int len = stoi(s.substr(i, delimiter - i));
            i = delimiter + 1; 

            result.push_back(s.substr(i, len));
            i += len;
        }

        return result;
    }
};
