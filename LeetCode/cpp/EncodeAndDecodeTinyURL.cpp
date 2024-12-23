class Solution
{
    // Space Complexity: O(n)
    // Time Complexity: O(1)
public:
    unordered_map<string, string> urlMap; // Maps short URL to long URL
    string baseUrl = "http://tinyurl.com/";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = baseUrl + to_string(urlMap.size() + 1);
        urlMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return urlMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));