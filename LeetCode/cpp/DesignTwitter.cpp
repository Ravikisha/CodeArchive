// Optimal Solution
class Twitter
{
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int count;

public:
    Twitter() : count(0) {}

    // Time Complexity: O(1)
    void postTweet(int userId, int tweetId)
    {
        tweetMap[userId].push_back(make_pair(count, tweetId));
        count++;
    }

    // Time Complexity: O(F+T)
    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        priority_queue<vector<int>> maxHeap;

        // Add the user to their own follow set if not already present
        followMap[userId].insert(userId);
        // get all the followers
        for (int followeeId : followMap[userId])
        {
            // check the followers has any posts
            if (tweetMap.find(followeeId) != tweetMap.end())
            {
                // get the recent tweet of the followee
                int index = tweetMap[followeeId].size() - 1;
                pair<int, int> countAndTweetId = tweetMap[followeeId][index];
                maxHeap.push({countAndTweetId.first, countAndTweetId.second,
                              followeeId, index - 1});
            }
        }
        // collect the 10 most recent tweets
        while (!maxHeap.empty() && result.size() < 10)
        {
            vector<int> values = maxHeap.top();
            maxHeap.pop();
            result.push_back(values[1]);
            if (values[3] >= 0)
            {
                pair<int, int> countAndTweetId = tweetMap[values[2]][values[3]];
                maxHeap.push({countAndTweetId.first, countAndTweetId.second,
                              values[2], values[3] - 1});
            }
        }
        return result;
    }

    // Time Complexity: O(1)
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {                                             // Avoid self-following
            followMap[followerId].insert(followeeId); // Fix: Use insert
        }
    }

    // Time Complexity: O(1)
    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId && followMap[followerId].count(followeeId))
        {
            followMap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

// More Optimal Solution using Deque
class Twitter
{
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, deque<pair<int, int>>> tweetMap;
    int count;
    static const int MAX_TWEETS = 10;

public:
    Twitter() : count(0) {}

    void postTweet(int userId, int tweetId)
    {
        if (tweetMap[userId].size() == MAX_TWEETS)
        {
            tweetMap[userId].pop_front(); // Keep only the last 10 tweets
        }
        tweetMap[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        priority_queue<vector<int>> maxHeap;

        followMap[userId].insert(userId); // Ensure self-follow

        for (int followeeId : followMap[userId])
        {
            if (tweetMap.find(followeeId) != tweetMap.end())
            {
                int index = tweetMap[followeeId].size() - 1;
                pair<int, int> countAndTweetId = tweetMap[followeeId][index];
                maxHeap.push({countAndTweetId.first, countAndTweetId.second, followeeId, index - 1});
            }
        }

        while (!maxHeap.empty() && result.size() < 10)
        {
            vector<int> values = maxHeap.top();
            maxHeap.pop();
            result.push_back(values[1]);
            if (values[3] >= 0)
            {
                pair<int, int> countAndTweetId = tweetMap[values[2]][values[3]];
                maxHeap.push({countAndTweetId.first, countAndTweetId.second, values[2], values[3] - 1});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
        {
            followMap[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId != followeeId && followMap[followerId].count(followeeId))
        {
            followMap[followerId].erase(followeeId);
        }
    }
};

// this second solution is more optimal
    // the tweetMap contain now only O(U x 10) where U is the numbers of users